all: tokeniser_testing

tokeniser_testing: tokeniser_testing.cpp dlib/all/source.cpp dlib/cpp_tokenizer.h
	g++ tokeniser_testing.cpp dlib/all/source.cpp -o tokeniser_testing
