#include<iostream>
using namespace std;

int split(string s, int n)
{
    int count0=0,count1=0;
    //count when both are equal 1s and 0s
    int cnt=0; 

    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            count0++;
        }else{
            count1++;
        }
        if(count0==count1){
            cnt++;
        }
    }
    return cnt;
}

int main(){
    string s = "0100110101";
    int n = s.length();

    cout << split(s,n);

    return 0;
}