class Solution
{
public:
    void solve(Node* root,int sum,int &maxsum, int len, int &maxlen){
        //base case
        if(root==NULL){
            //agr len jyada wali mil jae toh update kro
            if(len>maxlen){
                maxlen = len;
                maxsum = sum;
            }
            //agr dono ki length same hui toh
            else if(len==maxlen){
                maxsum = max(sum,maxsum);
            }
            return;
        }
        // initial sum value
        sum = sum + root->data;
        
        //recursivecalls
        solve(root->left,sum,maxsum,len+1,maxlen);
        solve(root->right,sum,maxsum,len+1,maxlen);
    }
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        int len = 0;
        int maxlen = 0;
        int sum = 0;
        int maxsum = INT_MIN;
        
        solve(root,sum,maxsum,len,maxlen);
        return maxsum;
    }
};