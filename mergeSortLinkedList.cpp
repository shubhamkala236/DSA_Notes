class Solution{
 public:
   //Function to sort the given linked list using Merge Sort.
   
   Node* merge(Node* left , Node* right)
   { 
     
     if(left==NULL) return right;
     if(right==NULL) return left;
     
     Node* dummynode = new Node(-1);
     Node* temp = dummynode;
     
     while(left && right){
       if(left->data < right->data){
          temp->next=left;
          temp=left;
          left=left->next;
       } else {
         temp->next=right;
         temp=right;
         right=right->next;
       }
     }
     
     while(left){
      temp->next=left;
      temp=left;
      left=left->next;
     }
     
     while(right){
       temp->next=right;
      temp=right;
      right=right->next;
      }
     
     
     return dummynode->next;
   }
   
   
   Node* FindMid(Node*head)
   {
     Node* slow = head;
     Node* fast = head->next;
     
     while(fast && fast->next)
     {
       slow=slow->next;
       fast=fast->next->next;
     }
     
     return slow;
   }
   
   
   Node* mergeSort(Node* head) 
   {
     // base case 
     
     if(head==NULL or head->next==NULL) {
        return head;
     }
     
     // break linked list into 2 halves to call recursion on both halves 
     
     Node* mid = FindMid(head);
     
     // now recursive calls on both halves and recursion will sort those halves
     
     Node* left = head;
     Node* right = mid->next;
     mid->next=NULL;
     
     left=mergeSort(left);
     right=mergeSort(right);
     
     // now both halve sorted , just merge both sorted LL 
     Node* result = merge(left,right);
     return result;
     
     
   }
};