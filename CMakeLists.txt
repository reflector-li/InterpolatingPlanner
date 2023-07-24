cmake_minimum_required(VERSION 3.10.2)
project(InterpolatingPlanner)
set(CMAKE_BUILD_TYPE "Debug")


find_package(Eigen3 REQUIRED)
find_package(Python3 COMPONENTS Interpreter Development REQUIRED)
find_package(Python3 COMPONENTS NumPy)


include_directories(./include)
link_directories(/usr/local/lib ./lib)

add_executable(main src/main.cpp lib/rs_path.cpp)

target_link_libraries(main Eigen3::Eigen Python3::Python
         Python3::Module Python3::NumPy
 )
