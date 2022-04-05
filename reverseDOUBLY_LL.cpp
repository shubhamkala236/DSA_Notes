    Node* reverseDLL(Node * head)
{
    //Your code here
     Node *curr = head;
   Node *prev = NULL;
   
   if(head == NULL){
       return NULL;
   }
   if(head->next == NULL){
       return head;
   }
   
   while(curr!=NULL){
       prev = curr->prev;
       curr->prev = curr->next;
       curr->next = prev;
       
       curr = curr->prev;
   }
   
   return prev->prev;
    
    
}