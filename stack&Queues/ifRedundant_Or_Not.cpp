#include<stack>
bool findRedundantBrackets(string &s)
{
    // Write your code here.
    stack <char> st;
    
    for(int i =0;i<s.length();i++){
        char ch = s[i];
        //aggr opening bracket ya operand hai toh stack me push in krdo
        if(ch=='(' ||ch=='+' ||ch=='-' ||ch=='*' ||ch=='/'){
            st.push(ch);
        }
        //agr closing hai toh ya koi english alphabet
        else{
            if(ch==')'){
                bool isRedundant = true;
                while(st.top()!='('){
                    char top = st.top();
                    if(top=='+' ||top=='-' ||top=='*' ||top=='/'){
                        isRedundant = false;
                    }
                    st.pop();
                }
                if(isRedundant == true){
                    return true;
                }
                //pop krre bracket ko taaki aage ke brackets ke lie kr ske
                st.pop();
            }
        }
    }
    return false;
}