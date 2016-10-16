#include "TokenizedFunctionList.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
	if (argc!=3)
	{
		cout << "Please input exactly 2 files." << endl;
		return 0;
	}

	vector<string> names;
	vector< vector<string> > functionNames (2,names);
	vector< vector<string> >& fCopy = functionNames;


	// Check it all works.
	vector< vector< vector<string> > > v = getFunctions(argv[1],argv[2],fCopy);

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
	}
}
