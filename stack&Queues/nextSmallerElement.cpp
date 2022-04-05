#include<stack>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    stack<int> s;
    // kyuki last element ka next smaller element toh kuch nhi hai
    //aur stack hum array ke peeche se daal rhe taaki n time hi krna ho  
    s.push(-1);
    vector<int> ans(n);
    
    for(int i=n-1;i>=0;i--){
        int curr = arr[i];
        // nhi hai agle me smaller toh tab tak htao jab tak mil na jaae
        while(s.top()>=curr){
            s.pop();
        }
        // mil gya chota element toh ans array me uske corresponding index me store krva do
        ans[i] = s.top();
        s.push(curr);
        
    }
    return ans;
}