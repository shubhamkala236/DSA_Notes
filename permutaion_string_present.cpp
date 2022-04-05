class Solution {
    private:
    bool checkEqual(int a[26],int b[26]){
        for (int i=0;i<26;i++){
            if(a[i]!=b[i])
            return 0;
        }
        return 1;
    }
public:
    bool checkInclusion(string s1, string s2) {
        // mapping the count of string 1
        int count1[26]={0};
        for(int i=0;i<s1.length();i++){
            int index = s1[i] -'a';
            count1[index]++;
        }
        
        // traverse the string 2 with window of 2 and mapping its count too
        
        int count2[26]={0};
        int i=0;
        int windowSize = s1.length();
        //running for first window
        while(i<windowSize && i<s2.length()){
        int index = s2[i] -'a';

            count2[index]++;
            i++;
        }
        if(checkEqual(count1,count2))
            return 1;
        
        // aage ki window process kro peeche wale ko delete krke and aage wale kko plus krke
        
        while(i<s2.length()){
            //current character we reached to and increased its count
            char newChar = s2[i];
            int index = newChar -'a';
            count2[index]++;
            // old character at index 2 behind from current 2 behind = windowSize
            char oldChar = s2[i-windowSize];
            index = oldChar -'a';
            count2[index]--;
            i++;
            if(checkEqual(count1,count2))
                return 1;
            
        }
        return 0;
    }
};