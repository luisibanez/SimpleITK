#include "image_types.h"
#include "itkImportImageFilter.h"
#include "sitkImageToThriftImageAdaptor.h"

namespace itk
{

namespace thrift
{

::thrift::Image
ImageAdaptor::Convert( const itk::simple::Image * inputImage )
{
  ::thrift::Image outputImage;
}


itk::simple::Image::Pointer
ImageAdaptor::Convert( const ::thrift::Image & inputImage )
{
  itk::simple::Image::Pointer outputImage;

  switch( inputImage.pixeltype )
  {
  case ::thrift::PixelType::Byte:
    {
    typedef signed char                  PixelType;
    const unsigned int                   Dimension = 2;  // TODO add switch for other dimensions

    typedef itk::Image< PixelType, Dimension >                ImageType;
    typedef itk::ImportImageFilter< PixelType, Dimension >    ImporterType;

    ImporterType::Pointer importer = ImporterType::New();

    bool LetFilterManageMemory = false;
    SizeValueType numberOfPixels = sizeof(PixelType) * inputImage.width * inputImage.height;

    PixelType * buffer = const_cast<PixelType*>( inputImage.buffer.data() );

    importer->SetImportPointer( buffer, numberOfPixels, LetFilterManageMemory);

    importer->Update();

    outputImage = new itk::simple::Image( importer->GetOutput() );

    break;
    }
  // TODO ... deal with the other potential pixel types.
  }

  return outputImage;
}


} // namespace thrift

} // namespace itk
