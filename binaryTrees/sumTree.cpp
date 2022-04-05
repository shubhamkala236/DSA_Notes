class Solution
{
    private:
    pair<bool,int> isSumtreeFast(Node * root){
        //base case
        if(root==NULL){
            pair<bool,int> p = make_pair(true,0);
            return p;
        }
        
        //leaf ko check nhi krna toh yeh kro 
        if(root->left==NULL && root->right==NULL){
            pair<bool,int> p = make_pair(true,root->data);
            return p;
        }
        
        pair<bool,int> leftAns = isSumtreeFast(root->left);
        pair<bool,int> rightAns = isSumtreeFast(root->right);
        
        bool left = leftAns.first;
        bool right = rightAns.first;
        
        bool condn = root->data == leftAns.second+rightAns.second;
        
        pair<bool,int> ans;
        
        if(left && right && condn){
            ans.first = true;
            ans.second = root->data + leftAns.second + rightAns.second;
            
        }else{
            ans.first = false;
        }
        return ans; 
    }
    public:
    bool isSumTree(Node* root)
    {
         // Your code here
         return isSumtreeFast(root).first;
    }
};