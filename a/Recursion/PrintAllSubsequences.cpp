#include<bits/stdc++.h>
using namespace std;

void printF(int idx,vector<int> &ds,int a[],int n)
{
     if(idx == n) 
     {
        for(auto it : ds){
        cout<<it<<" ";
        }
        if(ds.size() == 0)
        {
            cout<<"{}";
        }
     cout<<endl;
     return; 
     }
//take condition
ds.push_back(a[idx]);
printF(idx+1,ds,a,n);
ds.pop_back();   
//not pick
printF(idx+1,ds,a,n);
}

int main()
{
    int a[] = {3,1,2};
    int n = 3;
    vector<int> ds
    printF(0,ds,a,n);
}