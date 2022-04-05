void sortedInsert(stack<int> &stack, int num){
    //base case
    if(stack.empty() || (!stack.empty()) && stack.top()<num){
		stack.push(num);
        return;
    }
    //agr empty nhi hai aur top chota bhi nhi hai uss num se
    int n = stack.top();
    stack.pop();
    //recursive call
    sortedInsert(stack,num);
    //vapis jaate hue
    stack.push(n);
}
void sortStack(stack<int> &stack)
{
	// Write your code here
    //base case
    if(stack.empty()){
        return;
    }
    int num = stack.top();
    stack.pop();
    //recursie call
    sortStack(stack);
    //we got a empty stack now stored value which is num ko sorted manner
    //me daalo vapis
    sortedInsert(stack,num);
}