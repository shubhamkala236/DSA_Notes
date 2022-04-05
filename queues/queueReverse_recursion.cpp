void solve(queue<int> &q){
    //base case
    if(q.empty()){
        return;
    }
    if(q.size()==1){
        return;
    }
    
    int element = q.front();
    q.pop();
    solve(q);
    q.push(element);
}

queue<int> rev(queue<int> q)
{
    solve(q);
    return q;
    
}