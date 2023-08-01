cmake_minimum_required(VERSION 3.0)

project(CalculatorApi)

link_libraries(
    ${CMAKE_SOURCE_DIR}/lib/librestbed.4.8.dylib
    ${CMAKE_SOURCE_DIR}/lib/librestbed.4.dylib
    ${CMAKE_SOURCE_DIR}/lib/librestbed.dylib)

add_executable(CalculatorApi
    main.cpp
    CalcResourceFactory.cpp
    CalcService.cpp
    CalcServiceSettingsFactory.cpp)

target_include_directories(CalculatorApi PUBLIC
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/include/source)

set_property(TARGET CalculatorApi PROPERTY CXX_STANDARD 17 )