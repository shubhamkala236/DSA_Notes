queue<int> modifyQueue(queue<int> q, int k) {
    // add code here.
    stack<int> s;
    // insert into stack 
    for(int i = 0;i<k;i++){
        int val = q.front();
        q.pop();
        s.push(val);
    }
    //stack to queue as elements are reversed
    while(!s.empty()){
        int val = s.top();
        s.pop();
        q.push(val);
    }
    //placing element in right position 
    int n = q.size();
    int t = n-k;
    
    while(t--){
        int val = q.front();
        q.pop();
        q.push(val);
    }
    
    return q;
}