all: driver test

driver: driver.cpp TokenizedFunctionList.hpp dlib/all/source.cpp
	g++ driver.cpp TokenizedFunctionList.hpp dlib/all/source.cpp -o driver

test: tokeniser_testing.cpp dlib/all/source.cpp
	g++ tokeniser_testing.cpp dlib/all/source.cpp -o test

