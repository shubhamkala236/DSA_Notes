class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    //using a data structure map/array to store count of alphabets
		    
		    unordered_map<char,int> count;
		    //to store character one by one
		    queue<int> q;
		    
		    string ans ="";
		    
		    for(int i=0;i<A.length();i++){
		        char ch = A[i];
		        //increase count
		        count[ch]++;
		        
		        //queue me push kra
		        q.push(ch);
		        
		        while(!q.empty()){
		            if(count[q.front()]>1)
		            {
		                q.pop();
		            }
		            else
		            {
		                ans.push_back(q.front());
		                break;
		            }
		        }
		        //out of the while loop 2 cases either above if elese is done or while
		        //queue is empty, so if loop is empty there is no repeating in push '#'
		        if(q.empty()){
		            ans.push_back('#');
		        }
		    }
		    return ans;
		}
		

};