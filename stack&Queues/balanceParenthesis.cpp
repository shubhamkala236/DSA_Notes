class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++){
            char ch = s[i];
            // for opening bracket--> stack me push kro
            //for closed bracket check kro top phir pop kro ki matching pair hai ya nhi
            
            if(ch=='(' || ch=='{' || ch=='[')
            {
                st.push(ch);
            }else{
                
            
            //closing bracket hai ch toh check kro
            if(!st.empty()){
                char top = st.top();
                if((ch==')' && top=='(') || (ch=='}' && top=='{') || (ch==']' && top=='[')){
                    st.pop();
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }
      }
        //end me dekhege ki
        if(st.empty()){
            return true;
        }else{
            return false;
        }
    }
};