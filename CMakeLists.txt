cmake_minimum_required(VERSION 3.22)
project(Gym)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Gym
        Instructor.cpp
        Instructor.h
        Date.cpp
        Date.h
        Employee.cpp
        Employee.h
        ExerciseMachine.cpp
        ExerciseMachine.h
        FireDepartmentLicense.cpp
        FireDepartmentLicense.h
        Gym.cpp
        Gym.h
        GymLicense.cpp
        GymLicense.h
        main.cpp
        MinistryOfHealthLicense.cpp
        MinistryOfHealthLicense.h
        Person.cpp
        Person.h
        Trainee.cpp
        Trainee.h)
