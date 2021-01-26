find_package(Qt5Widgets REQUIRED)
set(CMAKE_AUTOMOC ON)
add_executable(helloworld HelloWorldMain.cpp HelloWorld.cpp)
# set_target_properties( helloQt PROPERTIES CMAKE_AUTOMOC ON )
target_link_libraries(
  helloworld
  project_warnings
  project_options
  Qt5::Widgets)
target_compile_features(helloworld PUBLIC cxx_nullptr cxx_lambdas)
