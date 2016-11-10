cmake_minimum_required (VERSION 3.5)
project (projet_elevage)
set(CMAKE_AUTOMOC ON)
# Directories
include_directories ("${PROJECT_SOURCE_DIR}/src")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

# Enable C++11
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

IF(CMAKE_COMPILER_IS_GNUCC)
	SET(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS}   -Wall -std=c11   -pthread -g")
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11 -pthread -g")
ENDIF(CMAKE_COMPILER_IS_GNUCC)


# Generate headers
set(DIA2CODE "${PROJECT_SOURCE_DIR}/dia2code/bin/dia2code")
exec_program(${DIA2CODE} ARGS -d ../src -ns Etats,Rendu -t cpp ../src/UMLprojet.dia)
#exec_program(${DIA2CODE} ARGS -d ../src -t cpp ../src/render.dia)

# Sources
file(GLOB_RECURSE main_sources src/*.cpp)


# Executables
add_executable(run ${main_sources})

# QT 
set(CMAKE_INCLUDE_CURRENT_DIR ON)
#set(CMAKE_AUTOMOC ON)

find_package(Qt5 COMPONENTS Gui Core Widgets)

# Dans le cas où il y a des fichiers ressources QT
#QT5_ADD_RESOURCES(RC_PACKAGE src/ressources.qrc)

target_link_libraries(run Qt5::Widgets Qt5::Core Qt5::Gui)
