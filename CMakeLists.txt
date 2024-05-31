cmake_minimum_required(VERSION 3.5)
project(fwc)

include(settings.cmake)

configure_file(configuration/app.h include/app.h @ONLY)

add_compile_options(-Wall -O2)

find_package(LibXml2 REQUIRED MODULE)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build)

aux_source_directory(${PROJECT_SOURCE_DIR}/src SRCS)
add_executable(fwc ${SRCS})
target_include_directories(fwc PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_include_directories(fwc PRIVATE ${PROJECT_SOURCE_DIR}/build/include)
if(WINPCAP_FOUND)
    target_include_directories(fwc SYSTEM PRIVATE ${LIBXML2_INCLUDE_DIR})
    target_link_libraries(fwc ${LIBXML2_LIBRARY})
else()
    message(FATAL_ERROR "LibXml2 Not Found")
endif()
