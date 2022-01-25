class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size(),0);

        int leftIndex = 0;
        int rightIndex = nums.size()-1;

        int resultIndex = result.size()-1;

        while(leftIndex<=rightIndex){
            if(nums[leftIndex]*nums[leftIndex]<=nums[rightIndex]*nums[rightIndex]){
                result[resultIndex] = nums[rightIndex]*nums[rightIndex];
                resultIndex--;
                rightIndex--;
            }else{
                result[resultIndex] = nums[leftIndex]*nums[leftIndex];
                resultIndex--;
                leftIndex++;
            }
        }
        return result;
    }
};