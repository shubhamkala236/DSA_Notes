class Solution {
public:
    void postorder(TreeNode* root, vector<int> &ans){
        //base case 
        if(root==NULL){
            return;
        }
        
        //recursive call
        //Left
        postorder(root->left,ans);
        //Right
        postorder(root->right,ans);
        //Node
        ans.push_back(root->val);

    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        
        postorder(root,ans);
        
        return ans;
    }
};