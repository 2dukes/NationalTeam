cmake_minimum_required(VERSION 3.15)
project(NTeam)

set(CMAKE_CXX_STANDARD 14)

add_executable(NTeam main.cpp Classes/NationalTeam.cpp Classes/NationalTeam.h Classes/Staff.cpp Classes/Staff.h Classes/Date.cpp Classes/Date.h Classes/OtherWorker.cpp Classes/OtherWorker.h Classes/SoccerPlayer.cpp Classes/SoccerPlayer.h Classes/InfCall.cpp Classes/InfCall.h Classes/Call.cpp Classes/Call.h Classes/Game.cpp Classes/Game.h Classes/Stats.cpp Classes/Stats.h)