class Solution{
  public:
  pair<int,int> solve(Node* root){
      //base case 
      
      if(root==NULL){
          pair<int,int> p = make_pair(0,0);
          return p;
      }
      
      pair<int,int> left = solve(root->left);
      pair<int,int> right = solve(root->right);
      
      pair<int,int> res;
      
      res.first = root->data + left.second + right.second;
      
      //4 me se left ka bhi max aur right ka bhi max kyuki 4 me se koi bhi adjacent nhi hai
      res.second = max(left.first,left.second) + max(right.first,right.second);
      
      return res;
  }
    //Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) 
    {
        // Add your code here
        pair <int,int> ans = solve(root);
        return max(ans.first,ans.second);
    }
};