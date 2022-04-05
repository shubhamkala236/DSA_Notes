class NStack
{
    int *arr;
    int *top;
    int *next;
    // n = stack number , s = size of array
    int n,s;
    int freespot;
public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        // Write your code here.
        n = N;
        s = S;
        arr = new int[s];
        top = new int [n];
        next = new int[s];
        
        // top initialize
        for(int i =0;i<n;i++){
            top[i]=-1;
        }
        //next initialize
        for(int i =0 ;i<s;i++){
            next[i] = i+1;
        }
        //update next for last index
        next[s-1] = -1;
        // intitial freespot is 0 th index in array
        freespot = 0;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // Write your code here.
        //check for overflow
        if(freespot==-1){
            return false;
        }
        //step-1 find the index to push
        int index = freespot;
        //step -2 update the free spot
        freespot = next[index];
        //step -3 insert in array the element u want to insert
        arr[index] = x;
        //step -4 updatee next as array now has new element and is not empty
        //next points to old top 
        next[index] = top[m-1];
        //step -5 update the top as new top is inserted already
        top[m-1] = index;
        
        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // Write your code here.
        //chek uunderflow condition
        if(top[m-1]==-1){
            return -1;
        }
        //and reverse  the steps of push operations
        int index = top[m-1];
        //nya top pichla top old top ho gya jo stored tha next wale array me
        top[m-1] = next[index];
        
        next[index] = freespot;
        freespot = index;
        return arr[index];
    }
};