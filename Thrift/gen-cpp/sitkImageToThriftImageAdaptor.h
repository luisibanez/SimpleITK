#include <sitkImage.h>
#include <image_types.h>
#include <image_constants.h>

namespace itk
{

namespace thrift
{

class ImageAdaptor
{
public:

   static ::thrift::Image Convert( const itk::simple::Image * inputImage );
   static itk::simple::Image::Pointer Convert( const ::thrift::Image & inputImage );

};


} // namespace thrift

} // namespace itk
