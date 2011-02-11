namespace cpp thrift

enum PixelType {
  Bool = 1,
  Byte = 2,
  Integer16 = 3,
  Integer32 = 4,
  Integer64 = 5,
  Double = 6,
  Binary = 7,
}

struct Image  {
  1: i64 width  = 1,
  2: i64 height = 1,
  3: i64 depth  = 1,
//  4: binary buffer,
  4: list<byte> buffer,
  5: PixelType pixeltype = 2,
  6: i16 endianness,
}

service AddImageFilter {
    Image execute(1:Image image1, 2:Image image2 ),
}

