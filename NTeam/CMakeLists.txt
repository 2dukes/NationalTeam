cmake_minimum_required(VERSION 3.15)
project(NTeam)

set(CMAKE_CXX_STANDARD 14)
include_directories(Classes)
add_executable(NTeam main.cpp Classes/NationalTeam.cpp Classes/NationalTeam.h Classes/Staff.cpp Classes/Staff.h Classes/Date.cpp Classes/Date.h Classes/OtherWorker.cpp Classes/OtherWorker.h Classes/SoccerPlayer.cpp Classes/SoccerPlayer.h Classes/InfCall.cpp Classes/InfCall.h Classes/Game.cpp Classes/Game.h Classes/Stats.cpp Classes/Stats.h Classes/TechnicalTeam.cpp Classes/TechnicalTeam.h Classes/Call.cpp Classes/Call.h)