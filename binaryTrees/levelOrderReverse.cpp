vector<int> reverseLevelOrder(Node *root)
{
    // code here
    vector<int> ans;
    stack<int> s;
    queue<Node*> q;
    
     if(root==NULL){
          return ans;
     }
    q.push(root);
    
    while(!q.empty()){
       Node * temp =q.front();
       q.pop();
       s.push(temp->data);
       if(temp->right){
           q.push(temp->right);
       }
       if(temp->left){
           q.push(temp->left);
       }
    }
    
    while(s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    
    return ans;
        
        
    }