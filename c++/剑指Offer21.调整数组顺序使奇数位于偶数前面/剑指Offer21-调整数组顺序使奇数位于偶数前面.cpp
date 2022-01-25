class Solution {
public:
    vector<int> exchange(vector<int>& nums) {

        int leftIndex = 0;
        int rightIndex = nums.size()-1;

        while(leftIndex<rightIndex){
            if((nums[leftIndex]%2==0) && (nums[rightIndex]%2!=0)){
                int tmp = nums[leftIndex];
                nums[leftIndex] = nums[rightIndex];
                nums[rightIndex] = tmp;

                leftIndex++;
                rightIndex--;
            }
            else if((nums[leftIndex]%2!=0) && (nums[rightIndex]%2!=0)){
                leftIndex++;
            }
            else if((nums[leftIndex]%2==0) && (nums[rightIndex]%2==0)){
                rightIndex--;
            }
            else{
                leftIndex++;
                rightIndex--;
            }
        }
        return nums;
    }
};