cmake_minimum_required(VERSION 2.8)

project(StructuredLightSim)
set(INCLUDE_DIRECTORIES include)
set(SRC
    src/DepthImageGenerator.cpp
    src/CameraSimulator.cpp
    src/EmitterSimulator.cpp)
set(INCLUDE
    include/DepthImageGenerator.h
    include/CameraSimulator.h
    include/EmitterSimulator.h)

find_package(Eigen3 3.3 REQUIRED NO_MODULE)
find_package(OpenCV REQUIRED)

add_executable(${PROJECT_NAME} "main.cpp" ${SRC} ${INCLUDE})
target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIRECTORIES}
                                                    ${EIGEN3_INCLUDE_DIR}
                                                    ${OpenCV_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} Eigen3::Eigen ${OpenCV_LIBS})
