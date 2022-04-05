// Method - 1
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo =0;
        int hi = nums.size() -1;
        
        while(lo<=hi)
        {
            int mid =(lo+hi)/2;
            if(nums[mid]==target) return mid;
            
            else if(nums[lo]<=nums[mid]){
                if(target>=nums[lo] && nums[mid]>target){
                    hi = mid-1;
                }else{
                    lo = mid -1;
                }
            }
            
            else if(nums[mid]<=nums[hi]){
                if(target>nums[mid] && nums[hi]>=target){
                    lo = mid + 1;
                }else{
                    hi = mid - 1;
                }
            }
        }
        return -1;
    }
};

// Method 2 
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int target_index=-1;
        int left=0;
        int  mid;
        int right=nums.size()-1;
        while(left<=right){
            mid=(left+right)/2;
            //when target is found
            if(nums[mid]==target){
                target_index= mid;
                break;
            }
            // finding target in left part (sorted) 
            else if(nums[left]<=nums[mid]){
                if(nums[left]<=target and nums[mid]>target){
                    right=mid-1;
                }
                else{
                    left=mid+1;
                }
            }
            // finding target in right sub part 
            else if(nums[mid]<=nums[right]){
                   if(target > nums[mid] && nums[right] >= target){
                      left = mid+1;
                     }
                else{
                  right = mid-1;
                }  
            }
             
            
        }
        return target_index;
    }
};