project(MyTableProject)
set(CMAKE_CXX_STANDARD 11)

add_executable(myProgram hex.cpp table.cpp)

target_include_directories(myProgram PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})