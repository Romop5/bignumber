cmake_minimum_required (VERSION 3.6)
project (BigNum)


option(BIGNUMBER_TEST "Compile & run tests" OFF)
option(BIGNUMBER_EXAMPLES "Compile examples" OFF)

set(BIGNUMBER_SRC 
	src/stringconversion.cpp
	src/number.cpp
	src/numberconversion.cpp
	)
add_library(bignumber ${BIGNUMBER_SRC})	
target_include_directories(bignumber PUBLIC "include" "src")

if(BIGNUMBER_EXAMPLES)
	add_executable(bignum test/main.cpp )
	target_link_libraries(bignum bignumber)
	add_executable(billionTest test/billion.cpp )
	target_link_libraries(billionTest bignumber)
	add_executable(equalTest test/conversionTest.cpp )
	target_link_libraries(equalTest bignumber)
	add_executable(power2 test/power2.cpp )
	target_link_libraries(power2 bignumber)
	add_executable(multiply test/mul.cpp )
	target_link_libraries(multiply bignumber)
	add_executable(powerperfm test/power2performance.cpp )
	target_link_libraries(powerperfm bignumber)
endif(BIGNUMBER_EXAMPLES)


if(BIGNUMBER_TEST)
	add_executable(veri test/verification.cpp )

	enable_testing()
	add_test("verification" veri)
endif(BIGNUMBER_TEST)

