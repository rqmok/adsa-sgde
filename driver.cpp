#include "TokenizedFunctionList.hpp"
#include <iostream>

// dummies for testing
int ZEESHANSFUNCTION(vector<string> v1, vector<string> v2)
{
	return 1;
}

bool ISCLONE(int matches, int size1,int size2)
{
	return true;
}

int main(int argc, char* argv[])
{
	// Currently, only checks 2 files.
	// I think it can easily be modified to work for more, though.

	if (argc!=3)
	{
		cout << "Please input exactly 2 files." << endl;
		return 0;
	}

	// Get the lists of tokens.
	// List of tokenised functions for file i is in v[i].
	// List of tokens in function j in file i is in v[i][j].
	// Name of function v[i][j] is stored in functionNames[i][j].
	vector<string> names;
	vector< vector<string> > functionNames (2,names);
	vector< vector<string> >& fCopy = functionNames;

	vector< vector< vector<string> > > v = getFunctions(argv[1],argv[2],fCopy);

	// Compare each function in each file against each function in each other file.
	for (int i=0; i<v.size(); i++)
	{
		for (int j=i+1; j<v.size(); j++)
		{
			for (int k=0; k<v[i].size(); k++)
			{
				for (int l=0; l<v[j].size(); l++)
				{
					// The function names in caps aren't done yet!
					int matchingLines = ZEESHANSFUNCTION(v[i][k],v[j][l]);
					if (ISCLONE(matchingLines,v[i][k].size(),v[j][l].size()))
					{
						string name1(argv[i+1]);
						string name2(argv[j+1]);
						cout << "Function " << functionNames[i][k] << " from file " << name1;
						cout << ", and function " << functionNames[j][l] << " from file " << name2;
						cout << " are clones." << endl;
					}
				}
			}
		}
	}
	

	// Testing the function tokeniser.
	/*
	for (int i=0; i<v.size(); i++)
	{
		cout << "Functions in file " << i+1 << ": \n\n";
		for (int j=0; j<v[i].size(); j++)
		{
			cout << "\nFunction name: " << functionNames[i][j] << endl;
			for (int k=0; k<v[i][j].size(); k++)
			{
				cout << v[i][j][k] << "\n";
			}
		}
		cout << "\n";
	}*/
}
