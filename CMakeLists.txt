cmake_minimum_required(VERSION 3.0.2)
project(simple_ros_node)

find_package(catkin REQUIRED COMPONENTS
  roscpp
)


catkin_package(
 CATKIN_DEPENDS roscpp
 DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

## Adding executables for emitter and reciever nodes
add_executable(emitter src/emitter.cpp)
target_link_libraries(emitter ${catkin_LIBRARIES})

add_executable(reciever src/reciever.cpp)
target_link_libraries(reciever ${catkin_LIBRARIES})
