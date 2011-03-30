#ifndef __sitkImportImageFilter_h
#define __sitkImportImageFilter_h

#include "sitkMacro.h"
#include "sitkImage.h"

#include "sitkPixelIDTokens.h"

#include "itkImageIOBase.h"

namespace itk {
  namespace simple {

    /** \class ImportImageFilter
     * \brief Compose a 2D or 3D image and return a smart pointer to a SimpleITK
     * image
     *
     * This filter is intended to interface SimpleITK to other image processing
     * libraries and applications that may have their own representation of an
     * image class.
     */
    class ImportImageFilter {
    public:
      typedef ImportImageFilter Self;

      Image* Execute();
      typedef Image* (Self::*MemberFunctionType)( Image* );

    protected:

      typedef itk::ImageIOBase::IOComponentType      IOComponentType;

      template < unsigned int VImageDimension >
      Image* ExecuteInternalImportScalar( IOComponentType componentType );

      template < unsigned int VImageDimension >
      Image* ExecuteInternalImportVector( IOComponentType componentType );

      // methods which utlize the EnableIf idiom to conditionally
      // instatiate ad execute the implementation
      template <class TImageType>
      typename EnableIf<IsInstantiated<TImageType>::Value, Image* >::Type
      ExecuteInternalScalar ( );
      template <class TImageType>
      typename DisableIf<IsInstantiated<TImageType>::Value, Image* >::Type
      ExecuteInternalScalar ( );

      template <class TImageType>
      typename EnableIf<IsInstantiated<TImageType>::Value, Image* >::Type
      ExecuteInternalVector ( );
      template <class TImageType>
      typename DisableIf<IsInstantiated<TImageType>::Value, Image* >::Type
      ExecuteInternalVector ( );

    private:

      unsigned int     m_NumberOfComponentsPerPixel;

      IOComponentType  m_PixelComponentType;

      unsigned int     m_ImageDimension;
    };
  }
}

#endif
