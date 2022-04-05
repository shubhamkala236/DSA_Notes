class Solution{
    private:
    int height(struct Node* node){
        // code here 
        //base case 
        if(node==NULL){
            return 0;
        }
        
        //recursive call
        int left = height(node->left);
        int right = height(node->right);
        
        int ans = max(left,right) + 1;
        
        return ans;
    }
    public:
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        //  base case 
        if(root==NULL){
            return true;
        }
        
        //recursive call to check for left and right sub tree
        // 3 conditions to check
        bool leftcheck = isBalanced(root->left);
        bool rightcheck = isBalanced(root->right);
        
        bool diff = abs(height(root->left)-height(root->right))<=1;
        
        if(leftcheck && rightcheck && diff){
            return 1;
        }
        else{
            return 0;
        }
        
    }
};