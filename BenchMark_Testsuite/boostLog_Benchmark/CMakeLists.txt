cmake_minimum_required(VERSION 3.10)

find_package(Boost COMPONENTS program_options log log_setup REQUIRED)

#add_library(BoostLog SHARED ./main.cpp)
#target_include_directories(BoostLog PUBLIC)
#target_link_libraries(BoostLog ${Boost_SYSTEM_LIBRARY})

add_executable(BoostLog ./main.cpp)
target_link_libraries(BoostLog ${Boost_LOG_LIBRARY} ${Boost_LOG_SETUP_LIBRARY})

set(CMAKE_CXX_FLAGS "-Wall -Wextra -fPIC -fopenmp  -DBOOST_LOG_DYN_LINK")
