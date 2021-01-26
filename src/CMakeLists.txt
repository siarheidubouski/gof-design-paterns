option(QT "Enable compilation of QT sample" OFF)

# qt
if(QT)
  message("Using Qt")
  add_subdirectory(qt)
endif()

# Generic test that uses conan libs
add_executable(intro main.cpp)
target_link_libraries(
  intro
  PRIVATE project_options
          project_warnings)
