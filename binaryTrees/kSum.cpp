class Solution{
  public:
    void solve(Node * root, int k , int &count, vector<int> path){
        //base case
        //path ho gya khatm
        if(root==NULL){
            return;
        }
        //initital array value of path
        //current root ka data hai stored in path array
        path.push_back(root->data);
        //left call
        solve(root->left,k,count,path);
        // right call
        solve(root->right,k,count,path);
        
        //check for K sum while coming back from base case
        int n = path.size();
        int sum = 0;
        
        for(int i = n-1; i>=0; i--){
            sum = sum + path[i];
            if(sum == k){
                count++;
            }
        }
        path.pop_back();
            
    }
    
    int sumK(Node *root,int k)
    {
        //path is a vector array to store total elements traversed in that path till now
        vector<int> path;
        int count = 0;
        solve(root,k,count,path);
        return count;
    }
};