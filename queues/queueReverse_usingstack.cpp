//Function to reverse the queue.
queue<int> rev(queue<int> q)
{
    // add code here.
    //Approach -1 using stack 
    stack<int> s;
    while(!q.empty()){
        int element = q.front();
        q.pop();
        s.push(element);
    }
    
    while(!s.empty()){
        int element = s.top();
        s.pop();
        q.push(element);
    }
    return q;
}