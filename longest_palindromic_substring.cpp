#include<iostream>
#include<string.h>
using namespace std;

void printSubStr(string str,int low,int high){
    for(int i=0;i<=high;i++){
        cout<<str[i];
    }
}

int longestPalSubstr(string str){
    int n =str.length();
    int maxLength =1, start=0;

    bool table[n][n];
    memset(table,0,sizeof(table));

// for 2 length strings only 

    for(int i=0;i<n-1;++i){
        if(str[i]==str[i+1]){
            table[i][i+1]=true;
            start=i;
            maxLength=2;
        }
    }

// for string length >=3 only and k is the length of the string
    for(int k=3;k<n;++k){
        // setting the start of string 
        for(int i=0;i<n-k+1;++i){
            //setting the end of string
            int j = i+k-1;

            if(table[i+1][j-1] && str[i]==str[j])
            {
                table[i][j]= true;
                if(k>maxLength){
                    start=i;
                    maxLength=k;
                }
            }
            
                
            }
        }
        cout<<"longest palindrome substring is :";
        printSubStr(str,start,start+maxLength-1);
        return maxLength;
    }



int main(){
    string str = "forgeeksskeegfor";
    cout << "\nLength is: "
         << longestPalSubstr(str);
    return 0;
}