#include "sitkExtractImageFilter.h"
#include "sitkMacro.h"

#include "itkVectorImage.h"

namespace itk {
namespace simple {

//----------------------------------------------------------------------------

  Image Extract ( const Image& image, size_t s, size_t d ) {
    ExtractImageFilter filter;
    return filter.Execute ( image, s, d );
  }


//
// Default constructor that initializes parameters
//
ExtractImageFilter::ExtractImageFilter ()
  {
  this->m_Slice = 0;
  this->m_Dimension = 2;
  this->m_MemberFactory.reset( new detail::MemberFunctionFactory<MemberFunctionType>( this ) );
  this->m_MemberFactory->RegisterMemberFunctions< PixelIDTypeList, 3 > ();
  }

//
// ToString
//
std::string ExtractImageFilter::ToString() const
  {
  std::ostringstream out;
  out << "itk::simple::ExtractImageFilter\n"
      << "\tSlice: " << this->m_Slice << "\n";
  return out.str();
  }


  Image ExtractImageFilter::Execute ( const Image& image, size_t s, size_t d )
  {
  this->m_Slice = s;
  this->m_Dimension = d;
  return Execute ( image );
  }

//
// Execute
//
Image ExtractImageFilter::Execute ( const Image &image )
  {

    PixelIDValueType type = image.GetPixelIDValue();
    unsigned int dimension = image.GetDimension();
    if ( dimension != 3 )
      {
      sitkExceptionMacro ( << "ExtractImageFilter operates on 3 dimensional images only" );
      }
    if (this->m_Dimension > 2)
      {
      sitkExceptionMacro ( << "ExtractImageFilter Dimension must be set to 0, 1, or 2" );
      }
    return this->m_MemberFactory->GetMemberFunction( type, dimension )( image );
  }

//----------------------------------------------------------------------------

//
// ExecuteInternal
//
template <class TImageType>
Image ExtractImageFilter::ExecuteInternal ( const Image& inImage )
  {
  typename TImageType::ConstPointer image =
    dynamic_cast <const TImageType*> ( inImage.GetImageBase() );

  if ( image.IsNull() )
    {
    sitkExceptionMacro( << "Could not cast input image to proper type" );
    }

  typedef itk::ExtractImageFilter<TImageType, TImageType> FilterType;
  typename FilterType::Pointer filter = FilterType::New();

  filter->SetInput ( image );

  typename TImageType::IndexType index;
  typename TImageType::SizeType size;
  index.Fill ( 0 );
  index[this->m_Dimension] = this->m_Slice;
  size = image->GetLargestPossibleRegion().GetSize();
  size[this->m_Dimension] = 1;
  typename TImageType::RegionType region ( index, size );

  filter->SetDirectionCollapseToSubmatrix();
  filter->SetExtractionRegion ( region );

  filter->Update();
  typename TImageType::Pointer filterOutput = filter->GetOutput();

  // Make the index 0,0,0
  //
  // FIX ME this changes the origin of the image, it is bad and a bug
  index.Fill ( 0 );
  region.SetIndex ( index );
  filterOutput->SetRegions ( region );

  return Image( filterOutput );
  }

} // end namespace simple
} // end namespace itk
