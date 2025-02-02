cmake_minimum_required(VERSION "3.10")

project("mavec")
set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_executable("${CMAKE_PROJECT_NAME}" "${SOURCES}")
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/headers/)

#set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY CXX_STANDARD 20)