#include<iostream>
#include<string.h>
using namespace std;

char * reverse(char *str){
    int i,length,n;
    char temp;
    length = strlen(str);
    n=length-1;                                    
    // n is the last character index = length - 1 which is to be replaced 
    for(i=0;i<=length/2;i++){
        temp=str[i];
        str[i]=str[n];
        str[n]=temp;
        n--;

    }
    return str;
}   
int main(){
        char My_string[] = "hello this is a string";
        cout<<"reversing the string ";
        reverse(My_string);
        cout<<My_string;
        return 0;

}