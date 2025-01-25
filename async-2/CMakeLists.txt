cmake_minimum_required(VERSION 3.20)

project(Template LANGUAGES CXX)

add_executable(main main.cc)

# If you want to override the C++ standard here, do:
set_property(TARGET main PROPERTY CXX_STANDARD 23)