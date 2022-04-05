// approach 1 by taking count of 0,1,2 and replaceing the data of linked list
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Add code here
        int zeroCount = 0;
        int oneCount = 0;
        int twoCount = 0;
        
        Node *temp = head;
        // counting the nos of 0,1,2
        while(temp!=NULL){
            if(temp->data==0){
                zeroCount++;
            }
            else if(temp->data==1){
                oneCount++;
            }else if(temp->data==2){
                twoCount++;
            }
            temp=temp->next;
        }
        
        //reset temp pointer to head
        temp = head;
        // replace the data 
        while(temp!=NULL){
            if(zeroCount!=0){
                temp->data=0;
                zeroCount--;
            }else if(oneCount!=0){
                temp->data=1;
                oneCount--;
            }else if(twoCount!=0){
                temp->data=2;
                twoCount--;
            }
            temp=temp->next;
        }
        return head;
        
    }
};


// Approach 2 by not replacing the data but replacing the linked

class Solution
{
    private:
    void insertAtTail(Node* &tail,Node* curr){
        //insert kra tail pe 
        tail->next = curr;
        //phir curr ki new value 
        curr=tail;
    }
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        // 3 dummy nodes at stating of 3 linked list 
        Node* zeroHead = new Node(-1);
        Node* oneHead = new Node(-1);
        Node* twoHead = new Node(-1);
        
        //tail to insert when we find new element of that list to insert at tail
        //initially at head
        Node * zeroTail = zeroHead;
        Node * oneTail = oneHead;
        Node * twoTail = twoHead;
        
        // creating seperate list for 0 , 1, 2 
        //traversing original list and comparing data
        Node * curr = head;
        while(curr!=NULL){
            int value = curr->data;
            
            if(value==0){
                //inserting current at zero ki list ke tail pr
                insertAtTail(zeroTail,curr);
            }
            else if(value==1){
                //inserting current at one ki list ke tail pr
                insertAtTail(oneTail,curr);
            }
            else if(value==2){
                //inserting current at two ki list ke tail pr
                insertAtTail(twoTail,curr);
            }
            
            curr = curr->next;
        }
        
        //Now merging all three list
        //if one ki list empty nhi hai tabhi 0 ki list merge krvaege
        if(oneHead->next!=NULL){
            zeroTail->next=oneHead->next;
        }else{
            //agr one ki list empty hai toh seedha 0 ko 2 ki list se merge krdo
            zeroTail->next = twoHead->next;
        }
        //baaki ki list ko krvaege ab
        oneTail->next = twoHead->next;
        twoTail->next = NULL;
        
        // remove dummy nodes
        //setup head
        head = zeroHead;
        //delete dummy nodes
        delete zeroHead;
        delete oneHead;
        delete twoHead;
        
        return head;
        
    }