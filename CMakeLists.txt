cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE DEBUG)

set(IOLIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/iolib)
set(CLIENT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/client)
set(REMOTE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/remote)

# directories
include_directories(
    ${IOLIB_DIR}
    ${CLIENT_DIR}
    ${REMOTE_DIR}
)

# Pull in SDK (must be before project)
include(pico_sdk_import.cmake)

project(aircon C CXX ASM)

# initialize the SDK based on PICO_SDK_PATH
pico_sdk_init()

# ==================== FILES ====================

# client files
file(GLOB_RECURSE CLIENT_SOURCES ${CLIENT_DIR}/*.c  ${CLIENT_DIR}/*.cpp  ${CLIENT_DIR}/**/*.c  ${CLIENT_DIR}/**/*.cpp)
file(GLOB_RECURSE CLIENT_HEADERS  ${CLIENT_DIR}/*.h  ${CLIENT_DIR}/*.hpp  ${CLIENT_DIR}/**/*.h  ${CLIENT_DIR}/**/*.hpp)

# remote files
file(GLOB_RECURSE REMOTE_SOURCES  ${REMOTE_DIR}/*.c ${REMOTE_DIR}/*.cpp ${REMOTE_DIR}/**/*.c ${REMOTE_DIR}/**/*.cpp)
file(GLOB_RECURSE REMOTE_HEADERS ${REMOTE_DIR}/*.h ${REMOTE_DIR}/*.hpp ${REMOTE_DIR}/**/*.h ${REMOTE_DIR}/**/*.hpp)

# iolib files
file(GLOB_RECURSE IOLIB_SOURCES ${IOLIB_DIR}/*.c ${IOLIB_DIR}/*.cpp ${IOLIB_DIR}/**/*.c ${IOLIB_DIR}/**/*.cpp)
file(GLOB_RECURSE IOLIB_HEADERS ${IOLIB_DIR}/*.h ${IOLIB_DIR}/*.hpp ${IOLIB_DIR}/**/*.h ${IOLIB_DIR}/**/*.hpp)

# ==================== OUTPUTS ====================

# add the libraries
add_library(iolib ${IOLIB_SOURCES} ${IOLIB_HEADERS})

# add the executables
add_executable(client ${CLIENT_SOURCES} ${CLIENT_HEADERS})
add_executable(remote ${REMOTE_SOURCES} ${REMOTE_HEADERS})


# ==================== INCLUDES ====================

# iolib libs
target_include_directories(iolib PUBLIC ${CMAKE_SOURCE_DIR}/src/)
target_link_libraries(iolib pico_stdlib)

# client libs
target_include_directories(client PUBLIC ${CMAKE_SOURCE_DIR}/src/)
target_link_libraries(client PRIVATE  iolib)

# remote libs
target_include_directories(remote PUBLIC ${CMAKE_SOURCE_DIR}/src/)
target_link_libraries(remote PRIVATE iolib)

# create uf2 file
pico_add_extra_outputs(client)
pico_add_extra_outputs(remote)