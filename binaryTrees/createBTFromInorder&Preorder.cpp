class Solution{
    public:
    // mapping node to index value in inorder array
    void createMapping(int in[],map<int,int> &nodeToIndex, int n){
        for(int i=0;i<n;i++){
            nodeToIndex[in[i]] = i;
        }
    }
    // solve function
    Node * solve(int in[],int pre[], int &index, int inOrderStart, int inOrderEnd, int n, map<int,int> &nodeToIndex)
    {
        //base case
        //preorder array finished OR indorderstart > inorderEnd
        if(index>=n || inOrderStart > inOrderEnd){
            return NULL;
        }
        
        //take index(preorderIndex) as root element
        int element = pre[index++];
        
        //Create new node from that element
        Node * root = new Node(element);
        // find position of that element in inOrder array from map 
        int position = nodeToIndex[element];
        
        //recursive calls to do same for left and right parts which will be crated
        
        root->left = solve(in,pre,index,inOrderStart,position-1,n,nodeToIndex);
        root->right = solve(in,pre,index,position+1,inOrderEnd,n,nodeToIndex);
        
        return root;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        int preOrderIndex = 0;
        //map to map the every index for each Node/value
        map<int,int> nodeToIndex;
        //fuction to put index into map according to their respective Node in inorder array
        createMapping(in,nodeToIndex,n);
        
        Node * ans = solve(in,pre,preOrderIndex,0,n-1,n,nodeToIndex);
        
        return ans;
    }
};