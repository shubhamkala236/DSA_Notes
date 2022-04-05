#include <iostream>
using namespace std;
 
int kth(int arr1[], int arr2[], int m, int n, int k)
{
    int sorted1[m + n];
    int i = 0, j = 0, d = 0;
    while (i < m && j < n)
    {
        if (arr1[i] < arr2[j])
            sorted1[d++] = arr1[i++];
        else
            sorted1[d++] = arr2[j++];
    }
    while (i < m)
        sorted1[d++] = arr1[i++];
    while (j < n)
        sorted1[d++] = arr2[j++];
    return sorted1[k - 1];
}
 
// Driver Code
int main()
{
    int arr1[5] = {2, 3, 6, 7, 9};
    int arr2[4] = {1, 4, 8, 10};
    int k = 5;
    cout << kth(arr1, arr2, 5, 4, k);
    return 0;
}

/////////////////////////////////OR///////////////////////////////


// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int kth)
    {
        // i and j are pointer tracking the two sorted arrays 
        // k is the pointer which is keeping a track of index of inserted elements
        int k = 0, i=0, j=0;
        
        while(i<m && j<n){
            // sorting in order without pushing into any new array
            if(arr1[i]<arr2[j]){
                k++;
                if(k==kth){
                    return arr1[i];
                    i++;
                }
            }else{
                k++;
                if(k==kth){
                    return arr2[j];
                    j++;
                }
            }
        }
        //if array 2 is completely traversed then return the remaining already sorted elements of arr1
        while(i<m){
            k++;
            if(k==kth){
                return arr1[i];
                i++;
            }
        }
        //if array 1 is completely traversed then return the remaining already sorted elements of arr2
        
        while(j<m){
            k++;
            if(k==kth){
                return arr2[j];
                j++;
            }
        }
        
    }
};

// { Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}  // } Driver Code Ends

