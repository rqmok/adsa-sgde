//
//  test.cpp
//  
//
//  Created by Simon Xie on 16/10/16.
//
//

#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Longest
{
public:
    
vector<string> longestCommonSubstring(vector<string> str1, vector<string> str2)
{


    int *curr = new int [str2.size()];
    int *prev = new int [str2.size()];

    int *swap = NULL;
    int maxSubstr = 0;
    vector<string> longest;
    for(unsigned int i = 0; i < str1.size(); ++i)
    {
        for(unsigned int j = 0; j < str2.size(); ++j)
        {
            if(str1[i] != str2[j])
            {
                curr[j] = 0;
            }
            else
            {
                if(i == 0 || j == 0)
                {
                    curr[j] = 1;
                }
                else
                {
                    curr[j] = 1 + prev[j-1];
                }
                if(maxSubstr < curr[j])
                {
                    maxSubstr = curr[j];
                    longest.clear();
                }
                if (maxSubstr == curr[j])
                {
                    longest.push_back(str1[i]);
                }
            }
        }
        swap=curr;
        curr=prev;
        prev=swap;
    }
    delete [] curr;
    delete [] prev;

    
    vector<string> transfer;
    vector<string> final;
    int index = 0;

	// special case
	if (longest.size() == 0)
		return transfer;
    
    for(int i = 0; i < str1.size();i++)
    {
        if(str1[i] == longest[0])
        {
		//cout << "entered loop, if statement worked" << endl;
            index = i;

            for(int j = i; (j >= i - maxSubstr+1)&(j>=0);j--)
            {
                transfer.push_back(str1[j]);
            }
        }
		//cout << "for loop done" << endl;
    }
    
    for(int i = transfer.size()-1; i >= 0;i--)
    {
        final.push_back(transfer[i]);
    }

    
    return final;
}
};

