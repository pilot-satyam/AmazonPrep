#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums)
{
    int n = nums.size();
    vector<vector<int>> res;
    sort(nums.begin(),nums.end());
    //moves for a
    for(int i=0;i<n-2;i++)
    {
        if(i==0 or (i>0 and nums[i]!=nums[i-1]))
        {
            int lo = i+1,hi = n-1;
            int sum = 0 - nums[i];
            while(lo < hi)
            {
                if(nums[lo] + nums[hi] == sum)
                {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[lo]);
                    temp.push_back(nums[hi]);
                    res.push_back(temp);
                    while(lo < hi and nums[lo] == nums[lo+1]) lo++;
                    while(lo < hi and nums[hi] == nums[hi-1]) hi--;
                    lo++;
                    hi--;
                }
                else if(nums[lo] + nums[hi] < sum) lo++;
                else hi--;
            }
        }
        return res;
    }
}

int main()
{

}