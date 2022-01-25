class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int left = 0,right = nums.size() - 1;

        while(left<=right){
            int middle = (left+right)/2;
            if(target>nums[middle]){
                left = middle+1;
            }else if(target<nums[middle]){
                right = middle-1;
            }else{
                if(nums[left]!=target) left++;

                else if(nums[right]!=target) right--;
                
                else break;
            }
        }
        return right-left+1;
    }
};