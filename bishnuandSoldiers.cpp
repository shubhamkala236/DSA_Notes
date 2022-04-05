// naive approach 
#include<bits/stdc++.h>

using namespace std;

#define ll long long


 

int main()

{

    int n;

    cin>>n;

    int ar[n];

    for(int i=0;i<n;i++)

    {

        cin>>ar[i];

    }

    int t;

    cin>>t;

    while(t--)

    {

        int sum=0,count=0;

        int p;

        cin>>p;

        for(int i=0;i<n;i++)

        {

            if(ar[i]<=p){

            sum+=ar[i];

            count++;}

        }

        cout<<count<<" "<<sum<<endl;


 

    }

}

// binary serach approach
#include <iostream>

#include <algorithm>

using namespace std;

typedef long long ll;

 

ll getScore(ll soldiers[],ll n,ll power){

    ll left=0;

    ll right=n-1;

    ll ans=-1;

    while(left<=right){

        ll mid=(right+left)/2;        

       if(soldiers[mid]>power){           

            right=mid-1;

        }

        else{

            ans=mid;

            left=mid+1;

        }

    }

    return ans+1;

};


 

int main() {

    ll num;

    cin >> num;

    ll soldiers[num];                               

    for(ll i=0;i<num;i++){

    cin>>soldiers[i];

    }

    sort(soldiers,soldiers+num);

    //prepocess the array to find cumulative power using prefix sum algorithm

    ll sum[num];

    sum[0]=soldiers[0];

    for(ll i=1;i<num;i++){

        sum[i]=sum[i-1]+soldiers[i];

    }

    ll Q;

    cin>>Q;

    for(ll i=0;i<Q;i++){

        ll q;

        cin>>q;

        ll res=getScore(soldiers,num,q);

        cout<<res<<" "<<sum[res-1]<<endl;

    }

}