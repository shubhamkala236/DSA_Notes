// approach 1 
class Solution {
    private:
    int getlength(ListNode * head){
        int len =0;
        while(head!=NULL){
            len++;
            head = head->next;
        }
        return len;
    }
public:
    ListNode* middleNode(ListNode* head) {
        int len = getlength(head);
        int mid = len/2;
        
        ListNode * temp = head;
        int cnt = 0;
        while(cnt<mid){
            temp=temp->next;
            cnt++;
        }
        return temp;
    }
};

//approach 2 slow and fast pointer

class Solution {
    private:
    ListNode* getMiddle(ListNode* head){
        // 0 or 1 node only
        if(head == NULL || head->next ==NULL){
            return head;
        }
        // 2 node
        if(head->next->next== NULL){
            return head->next;
        }
        
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while(fast!=NULL){
            //fast step 1
            fast = fast->next;
            if(fast!=NULL){
            // fast step 2
                fast = fast->next;
            }
            // slow step 
            slow = slow->next;
        }
        return slow;
        
    }
public:
    ListNode* middleNode(ListNode* head) {
        return getMiddle(head);
    }
};