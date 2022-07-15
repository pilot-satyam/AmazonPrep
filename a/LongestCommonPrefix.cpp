#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
      string ans = "";
        for(int i=0;i<strs[0].length();i++)
        {
             bool flag = true;
            char ch = strs[0][i];
            for(int j =1;j<strs.size();j++)
            {
                if(strs[j].size()<i or ch!=strs[j][i])
                {
                    flag = false;
                    //break;
                }
            }
            if(flag == false) break;
                else
                {
                    ans.push_back(ch);
                }
        }
        return ans;
    }
};