#==============================================================================
# CMakeLists file for file_crusade
#==============================================================================
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CURR_TARGET cbtek_kan_solo)

include(${CMAKE_MODULE_PATH}/flags.cmake)

set(CURR_TARGET_SOURCES "${CURR_TARGET}_SOURCES")
set(CURR_TARGET_FORMS "${CURR_TARGET}_FORMS")
set(CURR_TARGET_HEADERS "${CURR_TARGET}_HEADERS")
set(CURR_TARGET_HEADERS_NO_MOC "${CURR_TARGET}_HEADERS_NO_MOC")
set(CURR_TARGET_RESOURCES "${CURR_TARGET}_RESOURCES")

include_directories(src)
include_directories(inc)
include_directories(res)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
find_package(Qt5Widgets REQUIRED)

#==============================================================================
# Include Source Files
#==============================================================================
file(GLOB CURR_TARGET_SOURCES "src/*.cpp")
file(GLOB CURR_TARGET_FORMS "src/*.ui")
file(GLOB CURR_TARGET_HEADERS "inc/*.h*")
file(GLOB CURR_TARGET_RESOURCES "resx/*.qrc")

#==============================================================================
# Add Executable
#==============================================================================
add_executable(${CURR_TARGET}
               ${PLATFORM}
               ${CURR_TARGET_SOURCES}
               ${CURR_TARGET_HEADERS}
               ${CURR_TARGET_FORMS}
               ${CURR_TARGET_RESOURCES}
               )

#==============================================================================
# Add Dependencies
#==============================================================================

qt5_use_modules(${CURR_TARGET}
                 Widgets OpenGL)

add_dependencies(${CURR_TARGET}
                common_database
                common_utils)

#==============================================================================
# Target Link Libraries
#==============================================================================
if (WIN32)
    target_link_libraries(${CURR_TARGET}
                          common_database
                          common_utils
                          Qt5::Widgets                          
                          ${PTHREAD_LIB})
else()
    target_link_libraries(${CURR_TARGET}
                        common_database
                        common_utils
                        Qt5::Widgets                        
                        dl
                        pthread)
endif()

# Copy themes folder to build directory
# so that the exe can see them
add_custom_command(TARGET ${CURR_TARGET} POST_BUILD
               COMMAND ${CMAKE_COMMAND} -E copy_directory
                   ${CMAKE_CURRENT_SOURCE_DIR}/resx/themes $<TARGET_FILE_DIR:${CURR_TARGET}>/themes)
