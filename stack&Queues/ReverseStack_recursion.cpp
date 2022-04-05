void insertAtBottom(stack<int>& s, int x){
    //base case
    //agr khali hua toh bottom pe insert krdenge
    if(s.empty()){
        s.push(x);
        return; 
    }
    //store value of top before pop operation
    int store = s.top();
    s.pop();
    //recursive call - krte rha pop jab tak empty base condition meet na ho jae
    insertAtBottom(s,x);
    //value daal di base case ne bottom pr ab vapis jaate smay pop value jo
    //store me thi unhe vapis push kr do
    s.push(store);
    

}
void reverseStack(stack<int> &stack) {
    // Write your code here
    //base case 
    if(stack.empty()){
        return;
    }
    
    int store = stack.top();
    stack.pop();
    // recursive call
    reverseStack(stack);
    insertAtBottom(stack,store);
}