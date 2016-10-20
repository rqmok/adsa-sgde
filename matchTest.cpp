#include "MatchingTokens.hpp"
#include <iostream>

int main()
{
	vector<string> v1;
	v1.push_back("aa");

	vector<string> v2;
	v2.push_back("zz");
	v2.push_back("aa");
	v2.push_back("bb");

	cout << LCSFunction(v1,v2) << endl; // 1

	v1.push_back("bb");
	v2.push_back("aa");

	cout << LCSFunction(v1,v2) << endl; // 2

	vector<string> v3;
	v3.push_back("a");
	v3.push_back("b");
	v3.push_back("c");
	v3.push_back("d");
	v3.push_back("e");
	v3.push_back("f");
	v3.push_back("g");
	v3.push_back("h");

	vector<string> v4;
	v4.push_back("a");
	v4.push_back("b");
	v4.push_back("cs");
	v4.push_back("d");
	v4.push_back("e");
	v4.push_back("fs");
	v4.push_back("i");
	v4.push_back("j");
	v4.push_back("g");
	v4.push_back("h");

	cout << LCSFunction(v3,v4) << endl; // 6

	vector<string> v5;
	v5.push_back("a");
	v5.push_back("a");
	v5.push_back("a");
	v5.push_back("a");
	v5.push_back("a");

	vector<string> v6;
	v6.push_back("b");
	v6.push_back("b");
	v6.push_back("b");
	v6.push_back("b");
	v6.push_back("b");
	v6.push_back("b");
	v6.push_back("b");

	cout << LCSFunction(v5,v6) << endl; // 0
}

