class Solution{
    private:
    //next smaller
        vector<int> nextSmallerElement(int * arr, int n){
        stack<int>s;
        s.push(-1);
        vector<int> ans(n);
        
        for(int i=n-1;i>=0;i--){
            int curr = arr[i];
            
            while(s.top()!=-1 && arr[s.top()]>=curr){
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    //previos smaller element
        vector<int> prevSmallerElement(int *arr, int n){
        stack<int>s;
        s.push(-1);
        vector<int> ans(n);
        
        for(int i=0;i<n;i++){
            int curr = arr[i];
            
            while(s.top()!=-1 && arr[s.top()]>=curr){
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    //largest rectangle 
    
    int largestRectangleArea(int *heights,int n) {
        // int n = heights.size();
        //for storing the index of next minimum element
        vector<int> next(n);
        next = nextSmallerElement(heights,n);
        
        // for storing the index of previous minimum element
        vector<int> prev(n);
        prev = prevSmallerElement(heights,n);
        int area = INT_MIN;
        // pattern we saw was next-prev-1 = width
        for(int i =0;i<n;i++){
            int l = heights[i];
            // is indexx of next is -1 which is not possible 
            if(next[i]==-1){
                next[i]=n;
            }
            int b = next[i]-prev[i] - 1;
            int newarea = l*b;
            area = max(area,newarea);
        }
        return area;
    }
    
    //maxarea of 1's
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        //isme first row compute hogi with size m
        int area = largestRectangleArea(M[0],m);
        
        for(int i =1;i<n;i++){
            for(int j=0;j<m;j++){
                //base 0 nhi hona chahiye kisi bhi building ka
                if(M[i][j]!=0)
                {
                    // update row value after adding previous row
                    M[i][j] = M[i][j] + M[i-1][j];
                }
                else
                {
                    M[i][j] = 0;
                }
            }
            // now entire row is updated kyuki j loop khtm ho gya toh saare col row ke upadated hai
            int newarea = largestRectangleArea(M[i],m);
            area = max(area,newarea);
        }
        return area;
    }
};