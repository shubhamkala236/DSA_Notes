bool knows(vector<vector<int> >& M,int a,int b,int n){
    if(M[a][b]==1){
        return true;
    }else{
        return false;
    }
}

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        //step 1 saare elements ko stack me daal do
        stack<int> s;
        
        for(int i = 0;i<n;i++){
            s.push(i);
        }
        
        //step-2 
        // jab tak sirf 1 na back jaae stack me tab tak
        //2 bande lo aur check kro ki voh aapas me ek doosre ko jante hai ya nhi
        while(s.size()>1){
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            //check kro ki 'a' 'b' ko janta hai ya nhi
            if(knows(M,a,b,n)){
                //agr janta hai toh b ko vapis daalo
                s.push(b);
            }else{
                s.push(a);
            }
        }
        // loop ke bahar aa gye matlab 1 element hai stack me potential candidate for celeb
        int candidate = s.top();
        //verify if celeb or not
        //rowcheck
        bool rowcheck = false;
        int zerocount = 0;
        for(int i = 0;i<n;i++){
            if(M[candidate][i]==0){
                zerocount++;
            }
            if(zerocount==n){
                rowcheck = true;
            }
        }
        //column check
        bool colcheck = false;
        int onecount = 0;
        for(int i = 0;i<n;i++){
            if(M[i][candidate]==1){
                onecount++;
            }
            if(onecount == n-1){
                colcheck = true;
            }
        }
        
        if(rowcheck==true && colcheck==true){
            return candidate;
        }
        else{
            return -1;
        }
    }
};