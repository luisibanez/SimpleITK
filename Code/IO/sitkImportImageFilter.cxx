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
      return this->ExecuteInternalScalar< itk::Image<int8_t, VImageDimension> >( );
      break;
    case itk::ImageIOBase::UCHAR:
      return this->ExecuteInternalScalar< itk::Image<uint8_t, VImageDimension> >( );
      break;
    case itk::ImageIOBase::SHORT:
      return this->ExecuteInternalScalar< itk::Image<int16_t, VImageDimension> >( );
      break;
    case itk::ImageIOBase::USHORT:
      return this->ExecuteInternalScalar< itk::Image<uint16_t, VImageDimension> >( );
      break;
    case itk::ImageIOBase::INT:
      return this->ExecuteInternalScalar< itk::Image<int32_t, VImageDimension> >( );
      break;
    case itk::ImageIOBase::UINT:
      return this->ExecuteInternalScalar< itk::Image<uint32_t, VImageDimension> >( );
      break;
    case itk::ImageIOBase::LONG:
      return this->ExecuteInternalScalar< itk::Image<long, VImageDimension> >( );
      break;
    case itk::ImageIOBase::ULONG:
      return this->ExecuteInternalScalar< itk::Image<unsigned long, VImageDimension> >( );
      break;
    case itk::ImageIOBase::FLOAT:
      return this->ExecuteInternalScalar< itk::Image<float, VImageDimension> >( );
      break;
    case itk::ImageIOBase::DOUBLE:
      return this->ExecuteInternalScalar< itk::Image<double, VImageDimension> >( );
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
      return this->ExecuteInternalVector< itk::VectorImage<signed char, VImageDimension> >( );
#if 0
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
#endif
  }


  template <class TImageType>
  typename EnableIf<IsInstantiated<TImageType>::Value, Image* >::Type
  ImportImageFilter::ExecuteInternalScalar( void )
  {

    typedef TImageType                        ImageType;
    typedef typename ImageType::PixelType     PixelType;
    const unsigned int Dimension = ImageType::ImageDimension;

    typedef itk::ImportImageFilter<PixelType,Dimension> Importer;

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
  ImportImageFilter::ExecuteInternalScalar( void )
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
