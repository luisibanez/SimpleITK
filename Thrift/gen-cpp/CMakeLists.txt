include_directories(
  /home/ibanez/local/thirft/include/thrift/
  /home/ibanez/src/Insight4/SimpleITK/Thrift/gen-cpp
  )

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

target_link_libraries(AddImageFilterServer ThriftImageLib)
