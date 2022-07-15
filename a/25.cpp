#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> v,int n)
{
    int max_from_right = v[n-1];
    v[n-1] = -1;
    for(int i=n-2;i>=0;i--)
    {
        int temp = v[i];
        v[i] = max_from_right;
        if(max_from_right < temp)
        max_from_right = temp;
    }
    for(int i = 0;i<n;i++)
    cout<<v[i]<<" ";
}

int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    solve(v,n);
}