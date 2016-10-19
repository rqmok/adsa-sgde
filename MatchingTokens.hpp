#include <iostream>
#include <vector>
#include "LCS.hpp"
using namespace std;

int searchLCS(vector<string> LCS, vector<string> list)
{
	int ret = -1;

	for (int i = 0; i < list.size(); i++)
	{
		if (list.at(i) == LCS.at(0))
		{
			ret = i;

			// The first element of LCS matches this iteration.
			// Check if the rest of the elements match as well.
			for (int j = 0; j < LCS.size(); j++)
			{
				if (list.at(i) != LCS.at(j))
				{
					break;
				}

				i++;
				if (i >= list.size())
					return -1;
			}
		}
	}

	return ret;
}

int LCSFunction(vector<string> list1, vector<string> list2)
{

	// Base case.
	if ((list1.size() == 0 || list2.size() == 0)
		|| (list1.size() == 1 && list2.size() == 1))
		return 0;


	// Get LCS from separate function.
	Longest l;
	vector<string> LCS = l.longestCommonSubstring(list1, list2);


	// Return 0 if LCS is empty.
	if (LCS.size() == 0)
		return 0;

	// Get element index for the element before the lcs.
	int list1Index = searchLCS(LCS, list1);

	// Return 0 if invalid.
	if (list1Index == -1)
		return 0;

	// Now for the second list.
	int list2Index = searchLCS(LCS, list2);

	// Return 0 if invalud.
	if (list2Index == -1)
		return 0;


	// Split first vector.
	vector<string> before_1(list1.begin(), list1.begin() + list1Index);
	vector<string> after_1((list1.begin() + list1Index) + LCS.size(), list1.end());

	// Split second vector.
	vector<string> before_2(list2.begin(), list2.begin() + list2Index);
	vector<string> after_2((list2.begin() + list2Index) + LCS.size(), list2.end());


	// Get numbers recursively.
	int numBefore = LCSFunction(before_1, before_2);
	int numAfter = LCSFunction(after_1, after_2);


	// Return size of code clone.
	return numBefore + numAfter + LCS.size();
}
