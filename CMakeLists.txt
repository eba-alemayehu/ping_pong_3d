cmake_minimum_required(VERSION 3.15)
project(lab32)

set(CMAKE_CXX_STANDARD 14)
set(linkers -lglut -lGLU -lGL)

#add_executable(main headers/Socket.cpp headers/Socket.h/)
#add_executable(recive recive.cpp headers/Socket.cpp headers/Socket.h)
add_executable(ping-pong3d_
        src/Ball.cpp headers/Ball.h
        src/Window.cpp headers/Window.h
        src/Table.cpp headers/Table.h
        src/Player.cpp headers/Player.h
        main.cpp
        )

target_link_libraries(ping-pong3d_ ${linkers})
#target_link_libraries(main)
#target_link_libraries(recive)