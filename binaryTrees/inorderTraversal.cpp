class Solution {
public:
    void inorder(TreeNode* root, vector<int> &ans){
        //base case 
        if(root==NULL){
            return;
        }
        
        //recursive call
        //Left
        inorder(root->left,ans);
        //Node
        ans.push_back(root->val);
        //Right
        inorder(root->right,ans);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
       
        vector<int> ans;
        
        inorder(root,ans);
        
        return ans;
    }
};