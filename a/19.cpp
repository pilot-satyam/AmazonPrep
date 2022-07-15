#include<bits/stdc++.h>
using namespace std;

bool solve(vector<int> &v,int n)
{
    unordered_map<int,int> m;
    for(auto i=0;i<n;i++)
    {
        m[v[it]]++;
    }
    int sum = 0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
             sum+=v[i]+v[j];
        }
    }
    for(auto it : m)
    {
        if(it.second == -(sum))
        return true;
    }
    return false;
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
    cout<<solve(v,n);
}

//To print The Triplets
// C++ program to find triplets in a given
// array whose sum is zero
#include<bits/stdc++.h>
using namespace std;

// function to print triplets with 0 sum
void findTriplets(int arr[], int n)
{
	bool found = false;

	for (int i=0; i<n-1; i++)
	{
		// Find all pairs with sum equals to
		// "-arr[i]"
		unordered_set<int> s;
		for (int j=i+1; j<n; j++)
		{
			int x = -(arr[i] + arr[j]);
			if (s.find(x) != s.end())
			{
				printf("%d %d %d\n", x, arr[i], arr[j]);
				found = true;
			}
			else
				s.insert(arr[j]);
		}
	}

	if (found == false)
		cout << " No Triplet Found" << endl;
}

// Driver code
int main()
{
	int arr[] = {0, -1, 2, -3, 1};
	int n = sizeof(arr)/sizeof(arr[0]);
	findTriplets(arr, n);
	return 0;
}
