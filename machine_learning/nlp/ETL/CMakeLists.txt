cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(ETL C CXX)

set(SOURCE_FILES ETL.cpp ETL.hpp)
add_library(ETL STATIC ${SOURCE_FILES})
set_property(TARGET ETL PROPERTY CXX_STANDARD 14)

