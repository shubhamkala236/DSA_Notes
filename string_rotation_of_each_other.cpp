#include<iostream>
#include<queue>
using namespace std;


bool check_rotation(string str1,string str2)
{
   if (str1.size()!=str2.size());   
   
   queue<char> q1;
   queue<char> q2;

   for (int i = 0; i < str1.size(); i++)
   {
      q1.push(str1[i]);
   }
   for (int i = 0; i < str2.size(); i++)
   {
      q2.push(str2[i]);
   }
   
   int k = str2.size();

   while (k--)
   {
      char ch= q2.front();
      q2.pop();
      q2.push(ch);

      if(q2 == q1){
         return true;
      }
   }
   return false;
   
   
}


int main()
{
    string s1 = "ABCD";
    string s2 = "CDAB";
    if (check_rotation(s1, s2))
        cout << s2 << " is a rotated form of " << s1
             << endl;
    else
        cout << s2 << " is not a rotated form of " << s1
             << endl;
    string s3 = "ACBD";
    if (check_rotation(s1, s3))
        cout << s3 << " is a rotated form of " << s1
             << endl;
    else
        cout << s3 << " is not a rotated form of " << s1
             << endl;
    return 0;
}