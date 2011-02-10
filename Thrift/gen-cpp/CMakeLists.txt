add_library(ThriftImageLib
  AddImageFilter.cpp
  image_constants.cpp
  image_types.cpp
  sitkImageToThriftImageAdaptor.cpp
  )

target_link_libraries(ThriftImageLib SimpleITKBasicFilters)

add_executable( AddImageFilterServer
  AddImageFilter_server.skeleton_implementation.cpp
  )

# link_directories( /home/ibanez/src/thirft/thrift-0.6.0/lib/cpp/.libs/ )

target_link_libraries(AddImageFilterServer ThriftImageLib
  /home/ibanez/src/thirft/thrift-0.6.0/lib/cpp/.libs/libthrift.a
)
