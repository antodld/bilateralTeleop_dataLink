cmake_minimum_required(VERSION 3.1)

set(CXX_DISABLE_WERROR 1)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)

set(PROJECT_NAME bilateralTeleop_dataLink)
set(PROJECT_VERSION 0.1.0)
set(PROJECT_DESCRIPTION "")
set(PROJECT_URL "")

# jrl-cmakemodules minimal settings
set(PROJECT_USE_CMAKE_EXPORT TRUE)
set(CXX_DISABLE_WERROR 1) # FIXME fix errors and re-enable

include(cmake/base.cmake)

project(${PROJECT_NAME} LANGUAGES CXX VERSION ${PROJECT_VERSION})

find_package(SpaceVecAlg REQUIRED)
find_package(Boost REQUIRED COMPONENTS serialization)

add_subdirectory(src)
