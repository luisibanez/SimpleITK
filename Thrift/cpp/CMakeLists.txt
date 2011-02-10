# add_executable(CppServer CppServer.cpp)

add_executable(CppClient CppClient.cpp)

target_link_libraries(CppClient ThriftImageLib
  /home/ibanez/src/thirft/thrift-0.6.0/lib/cpp/.libs/libthrift.a
)
