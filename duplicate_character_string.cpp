#include<iostream>
#include<map>
using namespace std;

void printDuplicate(string str){
    map<char,int> m;
    // working on string and then creating a map accordingly by incrementing value of a particular key we get from the string
    for(int i=0;i<str.length();i++){
        m[str[i]]++;
    }
// map created 
//then accessing that map through iterator and loop and if value count >1 means duplicate printing out that pair
    for(auto it: m){
        if(it.second>1){
            cout<<it.first<<", count ="<<it.second<<"\n";
            
        }
    }

}

int main(){
    string str ="testing string";
    printDuplicate(str);
    return 0;
}




