//Function to return a tree created from postorder and inoreder traversals.
void createMapping(int in[],map<int,int> &nodeToIndex, int n)
        {
            for(int i=0;i<n;i++)
            {
                nodeToIndex[in[i]] = i;
            }
        }

 Node * solve(int in[],int post[], int &index, int inOrderStart, int inOrderEnd, int n, map<int,int> &nodeToIndex)
    {
        //base case
        //postorder array finished OR indorderstart > inorderEnd
        if(index<0|| inOrderStart > inOrderEnd){
            return NULL;
        }
        
        //take index(postOrderIndex) as root element
        int element = post[index--];
        
        //Create new node from that element
        Node * root = new Node(element);
        // find position of that element in inOrder array from map 
        int position = nodeToIndex[element];
        
        //recursive calls to do same for left and right parts which will be crated
        // right call first kyuki right subtree phele aata hai LRN as traverse from back side so R comes first
        root->right = solve(in,post,index,position+1,inOrderEnd,n,nodeToIndex);
        root->left = solve(in,post,index,inOrderStart,position-1,n,nodeToIndex);
        
        return root;
    }        
    
Node *buildTree(int in[], int post[], int n) {
    // Your code here
    int postOrderIndex = n-1;
        //map to map the every index for each Node/value
        map<int,int> nodeToIndex;
        //fuction to put index into map according to their respective Node in inorder array
        createMapping(in,nodeToIndex,n);
        
        Node * ans = solve(in,post,postOrderIndex,0,n-1,n,nodeToIndex);
        
        return ans;
}