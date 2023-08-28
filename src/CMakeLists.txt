set(SRC
  sender.cpp
  receiver.cpp
)

set(HDR
  ../include/bilateralTeleop_dataLink/sender.h
  ../include/bilateralTeleop_dataLink/receiver.h
  ../include/bilateralTeleop_dataLink/type.h
  ../include/bilateralTeleop_dataLink/motion.h
  ../include/bilateralTeleop_dataLink/transformation.h
  ../include/bilateralTeleop_dataLink/serialize.h
)

add_library(${PROJECT_NAME} SHARED ${SRC} ${HDR})

target_link_libraries(${PROJECT_NAME} PUBLIC SpaceVecAlg::SpaceVecAlg)
target_link_libraries(${PROJECT_NAME} PUBLIC ${Boost_LIBRARIES})


set_target_properties(${PROJECT_NAME} PROPERTIES
  OUTPUT_NAME ${PROJECT_NAME}
  VERSION ${PROJECT_VERSION}
  PUBLIC_HEADER "${${PROJECT_NAME}_HDR}")

# Specify include directories for both compilation and installation process.
# The $<INSTALL_PREFIX> generator expression is useful to ensure to create
# relocatable configuration files, see https://cmake.org/cmake/help/latest/manual/cmake-packages.7.html
#creating-relocatable-packages
target_include_directories(${PROJECT_NAME} PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/bilateralTeleop_dataLink>"
  "$<INSTALL_INTERFACE:$<INSTALL_PREFIX>/${CMAKE_INSTALL_INCLUDEDIR}>")


install(TARGETS ${PROJECT_NAME}
  EXPORT "${TARGETS_EXPORT_NAME}"
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib)

install(
DIRECTORY ${CMAKE_SOURCE_DIR}/include/ DESTINATION include)

