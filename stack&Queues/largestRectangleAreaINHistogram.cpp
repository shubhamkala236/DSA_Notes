class Solution {
    private:
    vector<int> nextSmallerElement(vector<int> arr, int n){
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
    vector<int> prevSmallerElement(vector<int> arr, int n){
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
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
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
};