project(xorg-color-picker)
set(BIN_TARGET "${PROJECT_NAME}")

add_executable("${BIN_TARGET}" main.cpp x.cpp)

set( CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" "${CMAKE_SOURCE_DIR}/modules" )
find_package(X11 REQUIRED)
find_package(XFixes REQUIRED)

set_property(TARGET ${BIN_TARGET} PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET ${BIN_TARGET} PROPERTY CXX_STANDARD 11)
set_property(TARGET ${BIN_TARGET} PROPERTY CXX_EXTENSIONS OFF)

target_link_libraries(${BIN_TARGET} ${X11_LIBRARIES} ${XFIXES_LIBRARY})
