class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<int> result;
        int leftIndex = 0;
        int rightIndex = nums.size()-1;

        while(leftIndex<rightIndex){
            if(nums[leftIndex] + nums[rightIndex]<target){
                leftIndex++;
            }
            else if(nums[leftIndex] + nums[rightIndex]>target){
                rightIndex--;
            }
            else{
                result.push_back(nums[leftIndex]);
                result.push_back(nums[rightIndex]);
                break;
            }
        }
        return result;
    }
};