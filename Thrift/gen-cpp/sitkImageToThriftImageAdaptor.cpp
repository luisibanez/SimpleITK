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

  outputImage.width  = inputImage->GetWidth();
  outputImage.height = inputImage->GetHeight();

  itk::simple::PixelContainer::Pointer pixelContainer = inputImage->GetPixelContainer();

  outputImage.buffer = pixelContainer->GetBufferAsInt8();

  return outputImage;
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

    ImageType::RegionType  region;
    ImageType::IndexType   index;
    ImageType::SizeType    size;

    index.Fill(0);

    size[0] = inputImage.with;
    size[1] = inputImage.height;

    region.SetSize( size );
    region.SetIndex( index );

    import->SetRegion( region );

    bool LetFilterManageMemory = false;
    SizeValueType numberOfPixels = sizeof(PixelType) * inputImage.width * inputImage.height;

    PixelType * buffer = const_cast<PixelType*>( inputImage.buffer.data() );

    importer->SetImportPointer( buffer, numberOfPixels, LetFilterManageMemory);

    importer->Update();

    outputImage = new itk::simple::Image( importer->GetOutput() );

    importer->GetOutput()->Print( std::cout );

    break;
    }
  // TODO ... deal with the other potential pixel types.
  }

  return outputImage;
}


} // namespace thrift

} // namespace itk
