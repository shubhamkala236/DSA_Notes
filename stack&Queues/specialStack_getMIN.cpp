int mini;

void push(stack<int>& s, int a){
	// Your code goes here
	//agr stack empty hai toh insert kr do aur mini hoga vhi element
	if(s.empty()){
	    s.push(a);
	    mini = a;
	}
	else if(a<=mini)
	{
	    //formula to get a track for premin elemenent while popping
	    int val = 2*a-mini;
	    s.push(val);
	    mini = a;
	}else{
	    //if a is bigger than mini no new mini appeared
	    s.push(a);
	}
}

bool isFull(stack<int>& s,int n){
	// Your code goes here
	if(s.size()==n){
	    return true;
	}else{
	    return false;
	}
}

bool isEmpty(stack<int>& s){
	// Your code goes here
	if(s.empty()){
	    return true;
	}else{
	    return false;
	}
}

int pop(stack<int>& s){
	// Your code goes here
	if(s.empty()){
	    return -1;
	}
	
	int curr = s.top();
	s.pop();
	if(curr>mini){
	    return curr;
	}
	else
	{
	    int prevmini = mini;
	    int val = 2*mini-curr;
	    mini = val;
	    return prevmini;
	}
}

int getMin(stack<int>& s){
	// Your code goes here
	if(s.empty()){
	    return -1;
	}
	return mini;
}