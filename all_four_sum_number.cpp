vector<vector<int> > fourSum(vector<int> &nums, int target) {
       sort(nums.begin(),nums.end());
       int n=nums.size();
       vector<vector<int>>ans;
       for(int i=0;i<n;i++)
       {
           for(int j=i+1;j<n;j++)
           {
               int target2=target-nums[i]-nums[j];
               int left=j+1;
               int right=n-1;
               while(left<right)
               {
                   int two_sum=nums[left]+nums[right];
                   if(two_sum<target2)
                       left++;
                   else if(two_sum>target2)
                       right--;
                   else
                   {
                       int le=nums[left];
                       int ri=nums[right];
                       ans.push_back({nums[i],nums[j],nums[left],nums[right]});
                       while(left<right and nums[left]==le)
                           left++;
                       
                       while(left<right and nums[right]==ri)
                           right--;
                   }
               }
               while(j+1<n and nums[j+1]==nums[j])
                   j++;
           }
         while (i + 1 < n && nums[i + 1] == nums[i]) 
             i++;   
       }
     return ans;  
       
       
   }