void solve(stack<int>& s, int x){
    //base case
    //agr khali hua toh bottom pe insert krdenge
    if(s.empty()){
        s.push(x);
        return 
    }
    //store value of top before pop operation
    int store = s.top();
    s.pop();
    //recursive call - krte rha pop jab tak empty base condition meet na ho jae
    solve(s,x);
    //value daal di base case ne bottom pr ab vapis jaate smay pop value jo
    //store me thi unhe vapis push kr do
    s.push(store);
    
}
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    // Write your code here.
    solve(myStack,x);
    return myStack;
}