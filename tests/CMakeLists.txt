message("In /tests and Value of ${SOURCES} is " ${SOURCES}) 
add_executable(tests test.cpp catch.hpp ${SOURCES})
