class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	vector<int> ans;
    	
    	if(root==NULL){
    	    return ans;
    	}
    	
    	queue<Node*> q;
    	q.push(root);
    	bool leftToRight = true;
    	
    	while(!q.empty()){
    	    //level process
    	    int size = q.size();
    	    vector<int > tempans(size);
    	    
    	    for(int i=0;i<size;i++){
    	        Node * frontNode = q.front();
    	        q.pop();
    	        
    	        //normal order or reverse order 
    	        int index = leftToRight? i : size-i-1;
    	        tempans[index] = frontNode->data;
    	        
    	        if(frontNode->left){
    	            q.push(frontNode->left);
    	        }
    	        if(frontNode->right){
    	            q.push(frontNode->right);
    	        }
    	    }
    	    
    	   // direction change
    	   leftToRight = !leftToRight;
    	   
    	   for(auto it : tempans){
    	       ans.push_back(it);
    	   }
    	}
    	return ans;
    }
};
