all: driver

matchTest: matchTest.cpp MatchingTokens.hpp LCS.hpp
	g++ matchTest.cpp MatchingTokens.hpp LCS.hpp -o matchTest

driver: driver.cpp TokenizedFunctionList.hpp LCS.hpp MatchingTokens.hpp dlib/all/source.cpp
	g++ driver.cpp TokenizedFunctionList.hpp LCS.hpp MatchingTokens.hpp dlib/all/source.cpp -o driver

basicTest: tokeniser_testing.cpp dlib/all/source.cpp
	g++ tokeniser_testing.cpp dlib/all/source.cpp -o basicTest
