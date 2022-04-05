#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    int * arr[6] = {1,55,23,55,22,9};
    int n = 6;
    unordered_map <int ,int > mpp; 
    for (int i = 1 ; i <=n; i++)        
    {
       mpp[i]++;
    }

    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }
    for (auto it : mpp)
    {
        cout<<it.first<<" "<<it.second<<endl;
       
    }
    
    
    
}