cmake_minimum_required(VERSION 3.19)
project(StaffManagementSystem)

set(CMAKE_CXX_STANDARD 14)

add_executable(StaffManagementSystem
        Main/StaffManagerSystem_Main.cpp
        Header/workerManager.h Header/worker.h Header/employee.h Header/manager.h Header/boss.h
        Source/workerManager.cpp Source/employee.cpp Source/manager.cpp Source/boss.cpp
        )