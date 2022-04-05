class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int> ans;
        
        map<int,int> topNode;
        queue<pair<Node*,int>> q;
        
        q.push(make_pair(root,0));
        
        while(!q.empty()){
            pair<Node*,int> temp = q.front();
            q.pop();
            
            Node * frontNode = temp.first;
            int hd = temp.second;
            
            //maintain 1-1 mapping 
            //if one value is present for hd then do nothing do not add more to map
            
           // insert the updated value of bottom
            topNode[hd] = frontNode->data;
            
            
            if(frontNode->left){
                q.push(make_pair(frontNode->left,hd-1));
            }
            if(frontNode->right){
                q.push(make_pair(frontNode->right,hd+1));
            }
        }//while loop ends    
            
            for(auto i : topNode){
                ans.push_back(i.second);
            }
            
            return ans;
    }
};