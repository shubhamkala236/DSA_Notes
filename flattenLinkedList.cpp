Node *merge(Node* a, Node* b){
    if(a==NULL){
        return b;
    }
    if(b==NULL){
        return a;
    }
    // dummy node
    Node* result;
    
    if(a->data<b->data){
        result = a;
        result->bottom = merge(a->bottom,b);
        
    }else{
        result = b;
        result ->bottom = merge(a,b->bottom);
    }
    result->next == NULL;
    return result;
}
/*  Function which returns the  root of 
    the flattened linked list. */
Node *flatten(Node *root)
{
   // Your code here
   
   // base case 
   if(root == NULL || root->next==NULL){
       return root;
   }
   
   //recur for list on right
   //right wala part recursion smabhal lega 
   root->next = flatten(root->next);
   
   // merge
   root = merge(root,root->next);
   return root;
}