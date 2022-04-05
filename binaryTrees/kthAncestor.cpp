Node* solve(Node *root, int &k, int node){
    //base case 
    if(root==NULL){
        return NULL;
    }
    
    if(root->data==node){
        return root;
    }
    
    Node * leftAns = solve(root->left,k,node);
    Node * rightAns = solve(root->right,k,node);
    
    if(leftAns!=NULL && rightAns==NULL){
        k--;
        if(k<=0){
            //intmax taaki ans ko fix/ lock kr ske vhi sirf upar bhejenge koi aur root nhi kyuki k kabhi 0 nhi ho paega
            k=INT_MAX;
            return root;
        }
        return leftAns;
    }
    if(leftAns == NULL && rightAns != NULL)
    {
        k--;
        if(k <= 0)
        {
            k=INT_MAX;
            return root;
        }
        return rightAns;
    }

    
}

int kthAncestor(Node *root, int k, int node)
{
    // Code here
    Node* ans = solve(root,k,node);
    //ans->data== node hua toh usi se peeche toh jaa hi nhi skte toh -1 hi dedo
    if(ans==NULL || ans->data==node){
        return -1;
    }else{
        return ans->data;
    }
}