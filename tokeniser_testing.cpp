
/*
** This program just takes a single C++ file as an argument and
** prints its tokens and the type of the tokens in sequence.
*/

#include "dlib/cpp_tokenizer.h"
#include <string>
#include <iostream>
#include <fstream>

////////////////

// Defining types for the tokenizer. Don't mess with this!

// Define the tokenizer type
typedef dlib::tokenizer_kernel_1 tok;

// Define the queue type
typedef dlib::queue<dlib::cpp_tok_kernel_1_helper::token_text_pair>::sort_1b_c t_queue;

// Define the bst type
typedef dlib::binary_search_tree_kernel_1<std::string,char,dlib::default_memory_manager> set_bst;

// Define the set type
typedef dlib::set_kernel_1<std::string,set_bst> t_set;

// Define the cpp_tokenizer type
typedef dlib::cpp_tokenizer_kernel_1<tok, t_queue, t_set> cppTok;

////////////////

using namespace std;
using namespace dlib;

// This isn't strictly necessary, it just makes the output readable.

string typeConvert(int type)
{
	if (type==0)
		return "END_OF_FILE";
	if (type==1)
		return "KEYWORD";
	if (type==2)
		return "COMMENT";
	if (type==3)
		return "SINGLE_QUOTED_TEXT";
	if (type==4)
		return "DOUBLE_QUOTED_TEXT";
	if (type==5)
		return "IDENTIFIER";
	if (type==6)
		return "OTHER";
	if (type==7)
		return "NUMBER";
	if (type==8)
		return "WHITE_SPACE";
}

int main(int argc, char* argv[])
{
	cppTok cTok;

	if (argc!=2)
	{
		cout << "Please input exactly 1 file." << endl;
		return 0;
	}

	// Put file into stream.
	filebuf fb;
	if (fb.open(argv[1],ios::in))
	{

		istream file(&fb);

		cTok.set_stream(file);

		// Set up variables and references for the tokenizer to use.
		int type = 1;
		string token = "";
		int& typeCopy = type;
		string& tokenCopy = token;

		// Go until end of file.
		while (type!=0)
		{
			// Get the next token. Print the token and its type to the screen.

			cTok.get_token(typeCopy,tokenCopy);

			cout << "Token: " << token << ", Type: " << typeConvert(type) << endl;
		}
	}

}
