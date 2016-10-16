#include "dlib/cpp_tokenizer.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

/////////////////////////////////////////////////////////////////////////

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

/////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace dlib;




///////////
#include <iostream>

string typeConvert(int type)
{
	if (type==0)
		return "END_OF_FILE";
	else if (type==1)
		return "KEYWORD";
	else if (type==2)
		return "COMMENT";
	else if (type==3)
		return "SINGLE_QUOTED_TEXT";
	else if (type==4)
		return "DOUBLE_QUOTED_TEXT";
	else if (type==5)
		return "IDENTIFIER";
	else if (type==6)
		return "OTHER";
	else if (type==7)
		return "NUMBER";
	else
		return "WHITE_SPACE";
}



// Gets a list of tokens of an entire file, excluding
// whitespace, comments and EOF.
vector<string> tokenList(char* filename, vector<string>& tokensNamed)
{
	cppTok cTok;

	vector<string> list;

	// Put file into stream.
	filebuf fb;
	if (fb.open(filename,ios::in))
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
			// Get the next token. 

			cTok.get_token(typeCopy,tokenCopy);
			
			// Add token to list if it isn't EOF, comment or whitespace
			if (!((type==0)|(type==2)|(type==8)))
			{
				// If the token is a keyword or a symbol, put the token
				// itself in thr list. Otherwise, just put the type.
				if ((type==1)|(type==6))
				{
					list.push_back(token);
				}
				else
				{
					list.push_back(typeConvert(type));
				}

				tokensNamed.push_back(token);
			}
		}
	}

	return list;
}



// Returns a list of tokenised functions.
vector< vector<string> > functionList(vector<string> tokens, vector<string>& tokensNamed, vector<string>& funcNames)
{
	vector< vector<string> > funcs;

	int len = tokens.size();
	for (int i=0; i<len; i++)
	{
		string tok = tokens[i];

		// Might be the start of a function- look ahead.
		if (tok == "IDENTIFIER")
		{
			string name = tokensNamed[i];
			if ((i+1<len)&&(tokens[i+1]=="("))
			{
				// Put everything between the parentheses in the vector.
				vector<string> subList;
				subList.push_back(tok);
				subList.push_back(tokens[i+1]);

				for (i=i+2; i<len; i++)
				{
					subList.push_back(tokens[i]);
					if (tokens[i] == ")")
						break;
				}

				if ((i+1<len)&&(tokens[i+1]=="{"))
				{
					// Put everything between the brackets in the vector.
					int openBrackets = 0;
					for (i=i+1; i<len; i++)
					{
						tok = tokens[i];

						subList.push_back(tok);
						if (tok == "{")
							openBrackets++;
						if (tok == "}")
							openBrackets--;

						// When final bracket is closed, the function is over.
						if (openBrackets == 0)
						{
							funcs.push_back(subList);
							funcNames.push_back(name);
							break;
						}
					}
				}
			}
		}
	}
	return funcs;
}


vector< vector< vector<string> > > getFunctions(char* file1, char* file2, vector< vector<string> >& funcNames)
{
	// 3D nested vectors:
	// - A vector which is a list of tokens- a single function.
	// 	- A vector storing a list of functions
	// 		- A vector storing a list of a list of functions - each element contains
	// 		the functions of one file.
	// 
	vector< vector< vector<string> > > funcList;

	vector<string> names1;
	vector<string> names2;
	vector<string>& copy1 = names1;
	vector<string>& copy2 = names2;

	// Tokenise files
	vector<string> fileTokens1 = tokenList(file1,names1);
	vector<string> fileTokens2 = tokenList(file2,names2);

	vector<string>& funcNames1 = funcNames[0];
	vector<string>& funcNames2 = funcNames[1];

	// Seek functions.
	funcList.push_back(functionList(fileTokens1,names1,funcNames1));
	funcList.push_back(functionList(fileTokens2,names2,funcNames2));

	return funcList;
}



