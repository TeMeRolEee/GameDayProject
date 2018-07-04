cmake_minimum_required(VERSION 2.8.11)

project(OpswatAcademyQtExample)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Core HINTS /home/temerole/Qt/5.11.1/gcc_64/)
find_package(Qt5Widgets HINTS /home/temerole/Qt/5.11.1/gcc_64/)

# compiling
file(GLOB sources *.cpp)

add_executable(QtExample
    ${sources} Ball.cpp Ball.h Opponents.cpp Opponents.h Object.cpp Object.h)

# linking
target_link_libraries(QtExample Qt5::Core)
target_link_libraries(QtExample Qt5::Widgets)
