cmake_minimum_required (VERSION 3.6)
project (BigNum)


include_directories("src")
include_directories("vendor")
add_executable(bignum test/main.cpp)
add_executable(billionTest test/billion.cpp)
add_executable(equalTest test/conversionTest.cpp)
add_executable(veri test/verification.cpp)
add_executable(power2 test/power2.cpp)
