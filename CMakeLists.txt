cmake_minimum_required(VERSION 3.13)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_INCLUDE_CURRENT_DIR ON)

project(students-rating)


# Local header files here ONLY
SET(TARGET_H
    all_rating.h
    arg_parser.h
    errors.h
    crit_lib.h
    criteria.h
    marks.h
    strategy.h
    attendance.h
    pluses.h
    output.h
    students_sort.h
   )
set(SOURCES
  main.cpp
  all_rating.cpp
  arg_parser.cpp
  strategy.cpp
  output.cpp
  students_sort.cpp
)

find_package(Qt5Core CONFIG REQUIRED)
add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})
target_link_libraries(students-rating Qt5::Core)
