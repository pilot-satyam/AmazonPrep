#include<bits/stdc++.h>
using namespace std;

    /************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int floorInBST(TreeNode<int> * root, int key)
{
    int floor = -1;
    while(root){
    if(root->val == key)
    {
        floor = root->val;
        return floor;
    }
    else if(root->val < key)
    {
        floor = root->val;
        root = root->right;
    }
    else
    {
        
        root = root->left;
    }
    }
    return floor;
}


int main()
{

}