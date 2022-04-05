#include<stack>
int findMinimumCost(string str) {
  	
    //odd condition
    if(str.length()%2 == 1) {
        return -1;
    }
    
    stack<char> s;
    for(int i=0; i<str.length(); i++) {
        char ch = str[i];
        
        if(ch == '{') 
            s.push(ch);
		else
        {
            //ch is closed brace
            if(!s.empty() && s.top() == '{') {
                s.pop();
            }
            else
            {
                s.push(ch);
            }
        }
    }
    
        //stack contains invalid expression
        int a = 0, b = 0;
        while(!s.empty()) {
            if(s.top() == '{') {
                b++;
            }
            else
            {
                a++;
            }
            s.pop();
        }
        
		int ans = (a+1)/2 + (b+1)/2;
        return ans;
    
    
}

//without using stack
// C++ program to find minimum number of
// reversals required to balance an expression
#include <bits/stdc++.h>
using namespace std;

// Returns count of minimum reversals for making
// expr balanced. Returns -1 if expr cannot be
// balanced.
int countMinReversals(string expr)
{
	int len = expr.length();

	// Expressions of odd lengths
	// cannot be balanced
	if (len % 2 != 0) {
		return -1;
	}
	int left_brace = 0, right_brace = 0;
	int ans;
	for (int i = 0; i < len; i++) {
	
		// If we find a left bracket then we simply
		// increment the left bracket
		if (expr[i] == '{') {
			left_brace++;
		}
	
		// Else if left bracket is 0 then we find
		// unbalanced right bracket and increment
		// right bracket or if the expression
		// is balanced then we decrement left
		else {
			if (left_brace == 0) {
				right_brace++;
			}
			else {
				left_brace--;
			}
		}
	}
	ans = ceil(left_brace / 2.0) + ceil(right_brace / 2.0);
	return ans;
}

// Driver program to test above function
int main()
{
	string expr = "}}{{";
	cout << countMinReversals(expr);
	return 0;
}
