#include<bits/stdc++.h>
using namespace std;
#define ll long long

 // } Driver Code Ends
//User function template for C++

class Solution{
    public:
    //Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> arr, int n ) {
        //code here
        unordered_map <ll,ll> m;
        int count =0;
        ll presum =0;
        
        for(int i=0;i<n;i++){
            presum = presum + arr[i];
            
            if(presum == 0){
                
                count ++;
            }
            if(m.find(presum)!=m.end()){
                count = count + m[presum];
            }
                m[presum]++;
        }
        return count;
        
    }
};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n; //input size of array
       
        vector<ll> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr,n) << "\n";
    }
	return 0;
}  // } Driver Code Ends