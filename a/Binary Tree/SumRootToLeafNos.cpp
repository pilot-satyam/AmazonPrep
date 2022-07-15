class Solution {
public:
        int ans;
        void solve(TreeNode* root,int sum){
                if(root==NULL){
                        return;
                }
                sum=(sum*10)+root->val;
                if(root->left==NULL && root->right==NULL){
                        ans+=sum;
                        return;
                }
                if(root->left){
                        solve(root->left,sum);
                }
                if(root->right){
                        solve(root->right,sum);
                }
        }
    int sumNumbers(TreeNode* root) {
            int sum=0;
            ans=0;
            solve(root,sum);
            return ans;
        
    }
};