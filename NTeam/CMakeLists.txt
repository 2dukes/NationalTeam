cmake_minimum_required(VERSION 3.15)
project(NTeam)

set(CMAKE_CXX_STANDARD 14)
include_directories(Classes)
add_executable(NTeam main.cpp Classes/NationalTeam.cpp Classes/NationalTeam.h Classes/Staff.cpp Classes/Staff.h Classes/Date.cpp Classes/Date.h Classes/OtherWorker.cpp Classes/OtherWorker.h Classes/SoccerPlayer.cpp Classes/SoccerPlayer.h Classes/InfCall.cpp Classes/InfCall.h Classes/Game.cpp Classes/Game.h Classes/IndividualStatistics.cpp Classes/IndividualStatistics.h Classes/TechnicalTeam.cpp Classes/TechnicalTeam.h Classes/Call.cpp Classes/Call.h menuPresent.cpp menuPresent.h NecessaryFunctions_NameSpaces.cpp NecessaryFunctions_NameSpaces.h Classes/GameStats.cpp Classes/GameStats.h Classes/Exceptions.cpp Classes/Exceptions.h)

# Doxygen Build
find_package(Doxygen)
if(DOXYGEN_FOUND)
    set(BUILD_DOC_DIR "${CMAKE_SOURCE_DIR}/docs/output")
    if(NOT EXISTS "${BUILD_DOC_DIR}")
        file(MAKE_DIRECTORY "${BUILD_DOC_DIR}")
    endif()

    set(DOXYGEN_IN "${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile")
    set(DOXYGEN_OUT "${CMAKE_CURRENT_BINARY_DIR}/Doxyfile")
    configure_file("${DOXYGEN_IN}" "${DOXYGEN_OUT}" @ONLY)

    message("Doxygen build started")
    add_custom_target(Doxygen ALL
            COMMAND "${DOXYGEN_EXECUTABLE}" "${DOXYGEN_OUT}"
            WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM)
else(DOXYGEN_FOUND)
    message("Doxygen needs to be installed to generate the documentation.")
endif(DOXYGEN_FOUND)
