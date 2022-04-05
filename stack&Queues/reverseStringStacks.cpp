
class Solution {
public:
    void reverseString(vector<char>& s) {
        stack<char> stack;
        
        for(int i =0;i<s.size();i++){
            char ch = s[i];
            stack.push(ch);
        }
        
            int j=0;
            while(!stack.empty()){
                char store = stack.top();
                s[j] = store;
                stack.pop();
                j++;
            }
        
    
    }
};// modifying the same array without using extra space
class Solution {
public:
    void reverseString(vector<char>& s) {
        stack<char> stack;
        
        for(int i =0;i<s.size();i++){
            char ch = s[i];
            stack.push(ch);
        }
        //extra space
            vector<char>  ans;
            
            while(!stack.empty()){
                char store = stack.top();
                ans.push_back(store);
                stack.pop();
                
            }
        
    
    }
};

// with using ans array as extra space