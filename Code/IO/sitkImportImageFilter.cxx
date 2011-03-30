#ifdef _MFC_VER
#pragma warning(disable:4996)
#endif

#include "sitkImportImageFilter.h"

#include <itkImportImageFilter.h>
#include <itkImportVectorImageFilter.h>

// Header providing the list of pixel types
#include <itkImageIOBase.h>

#include <itkImage.h>
#include <itkVectorImage.h>

namespace itk {
  namespace simple {

   ImportImageFilter::ImportImageFilter() {
      this->m_BufferInt8 = NULL;
      this->m_BufferUnsignedInt8 = NULL;
      this->m_BufferInt16 = NULL;
      this->m_BufferUnsignedInt16 = NULL;
      this->m_BufferInt32 = NULL;
      this->m_BufferUnsignedInt32 = NULL;
      this->m_BufferLong = NULL;
      this->m_BufferUnsignedLong = NULL;
      this->m_BufferFloat = NULL;
      this->m_BufferDouble = NULL;
      }

    void ImportImageFilter::SetSpacing( const std::vector< double > &spacing ) {
      this->m_Spacing = spacing;
      }

    void ImportImageFilter::SetOrigin( const std::vector< double > &origin ) {
      this->m_Origin = origin;
      }

    void ImportImageFilter::SetSize( const std::vector< unsigned int > &size ) {
      this->m_Size = size;
      }

    void ImportImageFilter::SetBufferAsInt8( int8_t * buffer ) {
      this->m_BufferInt8 = buffer;
      }
    void ImportImageFilter::SetBufferAsUnsignedInt8( uint8_t * buffer ) {
      this->m_BufferUnsignedInt8 = buffer;
      }
    void ImportImageFilter::SetBufferAsInt16( int16_t * buffer ) {
      this->m_BufferInt16 = buffer;
      }
    void ImportImageFilter::SetBufferAsUnsignedInt16( uint16_t * buffer ) {
      this->m_BufferUnsignedInt16 = buffer;
      }
    void ImportImageFilter::SetBufferAsInt32( int32_t * buffer ) {
      this->m_BufferInt32 = buffer;
      }
    void ImportImageFilter::SetBufferAsUnsignedInt32( uint32_t * buffer ) {
      this->m_BufferUnsignedInt32 = buffer;
      }
    void ImportImageFilter::SetBufferAsLong( long * buffer ) {
      this->m_BufferLong = buffer;
      }
    void ImportImageFilter::SetBufferAsUnsignedLong( unsigned long * buffer ) {
      this->m_BufferUnsignedLong = buffer;
      }

    void ImportImageFilter::SetBufferAsFloat( float * buffer ) {
      this->m_BufferFloat = buffer;
      }
    void ImportImageFilter::SetBufferAsDouble( double * buffer ) {
      this->m_BufferDouble = buffer;
      }


    Image * ImportImageFilter::Execute () {

      Image * image = NULL;

      if ( this->m_NumberOfComponentsPerPixel == 1 ) {
        switch ( this->m_ImageDimension )
          {
          case 2:
            image = this->ExecuteInternalImportScalar<2>( this->m_PixelComponentType );
            break;
          case 3:
            image = this->ExecuteInternalImportScalar<3>( this->m_PixelComponentType );
            break;
          }
        }
      else {
        switch ( this->m_ImageDimension )
          {
          case 2:
            image = this->ExecuteInternalImportVector<2>( this->m_PixelComponentType );
            break;
          case 3:
            image = this->ExecuteInternalImportVector<3>( this->m_PixelComponentType );
            break;
          }
        }

      return image;
    }


  template < unsigned int VImageDimension >
  Image* ImportImageFilter::ExecuteInternalImportScalar( IOComponentType componentType )
  {
    switch(componentType)
    {
    case itk::ImageIOBase::CHAR:
      return this->ExecuteInternalScalar< itk::Image<int8_t, VImageDimension> >( this->m_BufferInt8 );
      break;
    case itk::ImageIOBase::UCHAR:
      return this->ExecuteInternalScalar< itk::Image<uint8_t, VImageDimension> >( this->m_BufferUnsignedInt8 );
      break;
    case itk::ImageIOBase::SHORT:
      return this->ExecuteInternalScalar< itk::Image<int16_t, VImageDimension> >( this->m_BufferInt16 );
      break;
    case itk::ImageIOBase::USHORT:
      return this->ExecuteInternalScalar< itk::Image<uint16_t, VImageDimension> >( this->m_BufferUnsignedInt16 );
      break;
    case itk::ImageIOBase::INT:
      return this->ExecuteInternalScalar< itk::Image<int32_t, VImageDimension> >( this->m_BufferInt32 );
      break;
    case itk::ImageIOBase::UINT:
      return this->ExecuteInternalScalar< itk::Image<uint32_t, VImageDimension> >( this->m_BufferUnsignedInt32 );
      break;
    case itk::ImageIOBase::LONG:
      return this->ExecuteInternalScalar< itk::Image<long, VImageDimension> >( this->m_BufferLong );
      break;
    case itk::ImageIOBase::ULONG:
      return this->ExecuteInternalScalar< itk::Image<unsigned long, VImageDimension> >( this->m_BufferUnsignedLong );
      break;
    case itk::ImageIOBase::FLOAT:
      return this->ExecuteInternalScalar< itk::Image<float, VImageDimension> >( this->m_BufferFloat );
      break;
    case itk::ImageIOBase::DOUBLE:
      return this->ExecuteInternalScalar< itk::Image<double, VImageDimension> >( this->m_BufferDouble );
      break;
    case itk::ImageIOBase::UNKNOWNCOMPONENTTYPE:
    default:
      assert( false ); // should never get here unless we forgot a type
      return NULL;
    }
  }


  template < unsigned int VImageDimension >
  Image* ImportImageFilter::ExecuteInternalImportVector( IOComponentType componentType )
  {
    switch(componentType)
    {
    case itk::ImageIOBase::CHAR:
      return this->ExecuteInternalVector< itk::VectorImage<signed char, VImageDimension> >( );
      break;
    case itk::ImageIOBase::UCHAR:
      return this->ExecuteInternalVector< itk::VectorImage<unsigned char, VImageDimension> >( );
      break;
    case itk::ImageIOBase::SHORT:
      return this->ExecuteInternalVector< itk::VectorImage<int16_t, VImageDimension> >( );
      break;
    case itk::ImageIOBase::USHORT:
      return this->ExecuteInternalVector< itk::VectorImage<uint16_t, VImageDimension> >( );
      break;
    case itk::ImageIOBase::INT:
      return this->ExecuteInternalVector< itk::VectorImage<int32_t, VImageDimension> >( );
      break;
    case itk::ImageIOBase::UINT:
      return this->ExecuteInternalVector< itk::VectorImage<uint32_t, VImageDimension> >( );
      break;
    case itk::ImageIOBase::LONG:
      return this->ExecuteInternalVector< itk::VectorImage<long, VImageDimension> >( );
      break;
    case itk::ImageIOBase::ULONG:
      return this->ExecuteInternalVector< itk::VectorImage<unsigned long, VImageDimension> >( );
      break;
    case itk::ImageIOBase::FLOAT:
      return this->ExecuteInternalVector< itk::VectorImage<float, VImageDimension> >( );
      break;
    case itk::ImageIOBase::DOUBLE:
      return this->ExecuteInternalVector< itk::VectorImage<double, VImageDimension> >( );
      break;
    case itk::ImageIOBase::UNKNOWNCOMPONENTTYPE:
    default:
      assert( false ); // should never get here unless we forgot a type
      return NULL;
    }
  }


  template <class TImageType>
  typename EnableIf<IsInstantiated<TImageType>::Value, Image* >::Type
  ImportImageFilter::ExecuteInternalScalar( typename TImageType::PixelType * pixelDataBuffer )
  {

    typedef TImageType                        ImageType;
    typedef typename ImageType::PixelType     PixelType;
    const unsigned int Dimension = ImageType::ImageDimension;

    typedef itk::ImportImageFilter<PixelType,Dimension> Importer;

    // if the InstantiatedToken is correctly implemented this should
    // not occur
    assert( ImageTypeToPixelIDValue<ImageType>::Result != (int)sitkUnknown );

    typename Importer::Pointer importer = Importer::New();

    //
    //  Origin
    //
    typename ImageType::PointType origin;
    std::copy( this->m_Origin.begin(), this->m_Origin.end(), origin.Begin() );
    importer->SetOrigin( origin );

    //
    //  Spacing
    //
    typename ImageType::SpacingType spacing;
    std::copy( this->m_Spacing.begin(), this->m_Spacing.end(), spacing.Begin() );
    importer->SetSpacing( spacing );

    //
    //  Size and Region
    //
    typename ImageType::RegionType region;
    typename ImageType::SizeType size;
    for(unsigned int si = 0; si < Dimension; si++ ) {
      size[si] = this->m_Spacing[si];
      }
    region.SetSize(size);
    importer->SetRegion( region );

    bool TheImportFilterWillTakeCareOfDeletingTheMemoryBuffer = false;

    //
    // Connect the Buffer
    //
    importer->SetImportPointer(
      pixelDataBuffer,
      region.GetNumberOfPixels(),
      TheImportFilterWillTakeCareOfDeletingTheMemoryBuffer);

    importer->Update();

    Image* image = new Image( importer->GetOutput() );

    return image;
  }


  template <class TImageType>
  typename EnableIf<IsInstantiated<TImageType>::Value, Image* >::Type
  ImportImageFilter::ExecuteInternalVector( void )
  {

    typedef TImageType                        ImageType;
    typedef typename ImageType::PixelType     PixelType;
    const unsigned int Dimension = ImageType::ImageDimension;

    typedef itk::ImportVectorImageFilter<PixelType,Dimension> Importer;

    // if the InstantiatedToken is correctly implemented this should
    // not occour
    assert( ImageTypeToPixelIDValue<ImageType>::Result != (int)sitkUnknown );

    typename Importer::Pointer importer = Importer::New();

    //
    //  TODO: FIXME:  Add here all the image information
    //
    //  Origin, Spacing, Direction, Buffer,...
    //

    importer->Update();

    Image* image = NULL; // FIXME new Image( importer->GetOutput() );

    return image;
  }


  template <class TImageType>
  typename DisableIf<IsInstantiated<TImageType>::Value, Image* >::Type
  ImportImageFilter::ExecuteInternalScalar( typename TImageType::PixelType * buffer )
  {
    typedef TImageType                      ImageType;
    sitkExceptionMacro( << "PixelType is not supported!" << std::endl
                        << "Pixel Type: "
                        << GetPixelIDValueAsString( ImageTypeToPixelIDValue<ImageType>::Result ) << std::endl
                        << "Refusing to load! " << std::endl );
    return NULL;
  }

  template <class TImageType>
  typename DisableIf<IsInstantiated<TImageType>::Value, Image* >::Type
  ImportImageFilter::ExecuteInternalVector( void )
  {
    typedef TImageType                      ImageType;
    sitkExceptionMacro( << "PixelType is not supported!" << std::endl
                        << "Pixel Type: "
                        << GetPixelIDValueAsString( ImageTypeToPixelIDValue<ImageType>::Result ) << std::endl
                        << "Refusing to load! " << std::endl );
    return NULL;
  }


  }
}
