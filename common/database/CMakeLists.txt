#==============================================================================
# CMakeLists file for database
#==============================================================================
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CURR_TARGET common_database)

set(CURR_TARGET_SOURCES "${CURR_TARGET}_SOURCES")
set(CURR_TARGET_HEADERS "${CURR_TARGET}_HEADERS")
set(CURR_TARGET_CONTRIB_SOURCES "${CURR_TARGET}_CONTRIB_SOURCES")
set(CURR_TARGET_CONTRIB_HEADERS "${CURR_TARGET}_CONTRIB_HEADERS")

if (WIN32)
    if (MINGW)
        add_definitions(-std=c++11)
    endif()
else()
    if (GCC)
        add_definitions(-std=c++11)
    endif()
endif()
#==============================================================================
# Include Source Files
#==============================================================================
#set(CURR_TARGET_SOURCES
file(GLOB CURR_TARGET_SOURCES "src/*.cpp"
                              "src/results/*.cpp"
                              "src/connections/*.cpp"
                              "src/types/*.cpp")

file(GLOB CURR_TARGET_HEADERS "inc/*.h*"
                              "inc/results/*.h*"
                              "inc/connections/*.h*"
                              "inc/types/*.h*")

file (GLOB CURR_TARGET_CONTRIB_HEADERS "contrib/sqlite/*.h")
file (GLOB CURR_TARGET_CONTRIB_SOURCES "contrib/sqlite/*.c*")


include_directories(inc)
include_directories(inc/types)
include_directories(inc/results)
include_directories(inc/connections)
#==============================================================================
# Add Library
#==============================================================================
add_library(${CURR_TARGET}
            ${LIBRARY_MODE}
            ${CURR_TARGET_SOURCES}
            ${CURR_TARGET_HEADERS}
            ${CURR_TARGET_CONTRIB_HEADERS}
            ${CURR_TARGET_CONTRIB_SOURCES})

#==============================================================================
# Add Dependencies
#==============================================================================
add_dependencies(${CURR_TARGET}
                 common_utils)

#==============================================================================
# Target Link Libraries
#==============================================================================
target_link_libraries(${CURR_TARGET}
                      common_utils)
