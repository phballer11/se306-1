cmake_minimum_required(VERSION 2.8.3)
project(team4_ros)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  genmsg
  message_generation
)

## System dependencies are found with CMake's conventions
# find_package(Boost REQUIRED COMPONENTS system)


## Uncomment this if the package has a setup.py. This macro ensures
## modules and global scripts declared therein get installed
## See http://ros.org/doc/api/catkin/html/user_guide/setup_dot_py.html
# catkin_python_setup()

################################################
## Declare ROS messages, services and actions ##
################################################

## To declare and build messages, services or actions from within this
## package, follow these steps:
## * Let MSG_DEP_SET be the set of packages whose message types you use in
##   your messages/services/actions (e.g. std_msgs, actionlib_msgs, ...).
## * In the file package.xml:
##   * add a build_depend and a run_depend tag for each package in MSG_DEP_SET
##   * If MSG_DEP_SET isn't empty the following dependencies might have been
##     pulled in transitively but can be declared for certainty nonetheless:
##     * add a build_depend tag for "message_generation"
##     * add a run_depend tag for "message_runtime"
## * In this file (CMakeLists.txt):
##   * add "message_generation" and every package in MSG_DEP_SET to
##     find_package(catkin REQUIRED COMPONENTS ...)
##   * add "message_runtime" and every package in MSG_DEP_SET to
##     catkin_package(CATKIN_DEPENDS ...)
##   * uncomment the add_*_files sections below as needed
##     and list every .msg/.srv/.action file to be processed
##   * uncomment the generate_messages entry below
##   * add every package in MSG_DEP_SET to generate_messages(DEPENDENCIES ...)

## Generate messages in the 'msg' folder
add_message_files(
 FILES 
 binIsFull.msg
 readyToUse.msg
 findPicker.msg
readyToExchange.msg
finishRotate.msg
arrived.msg
findVisitor.msg

)
#   FILES
#   Message1.msg
#   Message2.msg
# )

## Generate services in the 'srv' folder
# add_service_files(
#   FILES
#   Service1.srv
#   Service2.srv
# )

## Generate actions in the 'action' folder
# add_action_files(
#   FILES
#   Action1.action
#   Action2.action
# )

## Generate added messages and services with any dependencies listed here
 generate_messages(
   DEPENDENCIES
   std_msgs
 )

###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if you package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
CATKIN_DEPENDS message_runtime
#  INCLUDE_DIRS include
#  LIBRARIES team4_ros
#  CATKIN_DEPENDS roscpp std_msgs
#  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
# include_directories(include)
include_directories(
  ${catkin_INCLUDE_DIRS}
)

## Declare a cpp library
# add_library(team4_ros
#   src/${PROJECT_NAME}/team4_ros.cpp
# )


add_executable(AlphaRobotNode src/AlphaRobot.cpp)
target_link_libraries(AlphaRobotNode ${catkin_LIBRARIES})
add_dependencies(AlphaRobotNode ${catkin_EXPORTED_TARGETS})

add_executable(AlphaWithSensorRobotNode src/AlphaWithSensor.cpp)
target_link_libraries(AlphaWithSensorRobotNode ${catkin_LIBRARIES})
add_dependencies(AlphaWithSensorRobotNode ${catkin_EXPORTED_TARGETS})

add_executable(PickerNode src/Picker.cpp)
target_link_libraries(PickerNode ${catkin_LIBRARIES})
add_dependencies(PickerNode ${catkin_EXPORTED_TARGETS})

add_executable(CarrierNode src/Carrier.cpp)
target_link_libraries(CarrierNode ${catkin_LIBRARIES})
add_dependencies(CarrierNode ${catkin_EXPORTED_TARGETS})

add_executable(CarrierNode1 src/Carrier1.cpp)
target_link_libraries(CarrierNode1 ${catkin_LIBRARIES})
add_dependencies(CarrierNode1 ${catkin_EXPORTED_TARGETS})

add_executable(master_node src/Master.cpp)
target_link_libraries(master_node ${catkin_LIBRARIES})
add_dependencies(master_node ${catkin_EXPORTED_TARGETS})

add_executable(SwingRobotNode src/SwingRobot.cpp)
target_link_libraries(SwingRobotNode ${catkin_LIBRARIES})
add_dependencies(SwingRobotNode ${catkin_EXPORTED_TARGETS})

add_executable(DogNode src/Dog.cpp)
target_link_libraries(DogNode ${catkin_LIBRARIES})
add_dependencies(DogNode ${catkin_EXPORTED_TARGETS})

add_executable(PersonNode src/Person.cpp)
target_link_libraries(PersonNode ${catkin_LIBRARIES})
add_dependencies(PersonNode ${catkin_EXPORTED_TARGETS})


add_executable(bin_node src/Bin.cpp)
target_link_libraries(bin_node ${catkin_LIBRARIES})
add_dependencies(bin_node ${catkin_EXPORTED_TARGETS})

add_executable(bin_node_t src/BinTemp.cpp)
target_link_libraries(bin_node_t ${catkin_LIBRARIES})
add_dependencies(bin_node_t ${catkin_EXPORTED_TARGETS})

add_executable(bin_node_t2 src/BinTemp2.cpp)
target_link_libraries(bin_node_t2 ${catkin_LIBRARIES})
add_dependencies(bin_node_t2 ${catkin_EXPORTED_TARGETS})

add_executable(TractorWithWorkerNode src/TractorWithWorker.cpp)
target_link_libraries(TractorWithWorkerNode ${catkin_LIBRARIES})
add_dependencies(TractorWithWorkerNode ${catkin_EXPORTED_TARGETS})

add_executable(dog_node_1 src/dog1.cpp)
target_link_libraries(dog_node_1 ${catkin_LIBRARIES})
add_dependencies(dog_node_1 ${catkin_EXPORTED_TARGETS})

add_executable(dog_node_2 src/dog2.cpp)
target_link_libraries(dog_node_2 ${catkin_LIBRARIES})
add_dependencies(dog_node_2 ${catkin_EXPORTED_TARGETS})

add_executable(Visitor src/Visitor.cpp)
target_link_libraries(Visitor ${catkin_LIBRARIES})
add_dependencies(Visitor ${catkin_EXPORTED_TARGETS})

add_executable(Guider src/Guider.cpp)
target_link_libraries(Guider ${catkin_LIBRARIES})
add_dependencies(Guider ${catkin_EXPORTED_TARGETS})

## Declare a cpp executable
# add_executable(team4_ros_node src/team4_ros_node.cpp)
add_executable(sensor_node src/mypub.cpp)

## Add cmake target dependencies of the executable/library
## as an example, message headers may need to be generated before nodes
#add_dependencies(team4_ros_node team4_ros_generate_messages_cpp)


## Specify libraries to link a library or executable target against
 target_link_libraries(sensor_node
   ${catkin_LIBRARIES}
 )


#############
## Install ##
#############

# all install targets should use catkin DESTINATION variables
# See http://ros.org/doc/api/catkin/html/adv_user_guide/variables.html

## Mark executable scripts (Python etc.) for installation
## in contrast to setup.py, you can choose the destination
# install(PROGRAMS
#   scripts/my_python_script
#   DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark executables and/or libraries for installation
# install(TARGETS team4_ros team4_ros_node
#   ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark cpp header files for installation
# install(DIRECTORY include/${PROJECT_NAME}/
#   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
#   FILES_MATCHING PATTERN "*.h"
#   PATTERN ".svn" EXCLUDE
# )

## Mark other files for installation (e.g. launch and bag files, etc.)
# install(FILES
#   # myfile1
#   # myfile2
#   DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
# )

#############
## Testing ##
#############

## Add gtest based cpp test target and link libraries
# catkin_add_gtest(${PROJECT_NAME}-test test/test_team4_ros.cpp)
# if(TARGET ${PROJECT_NAME}-test)
#   target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME})
# endif()

find_package(rostest REQUIRED)
find_package(gtest)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

add_rostest_gtest(AlphaRobotTest test/alpharobot.test test/AlphaRobotTest.cpp)

## Add folders to be run by python nosetests
# catkin_add_nosetests(test)
