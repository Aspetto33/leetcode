class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slowIndex = 0;
        int fastIndex = 0;
        
        while(fastIndex<nums.size()){
            if(nums[fastIndex]!=val){
                nums[slowIndex++]=nums[fastIndex];
            }
            fastIndex++;
        }
        return slowIndex;
    }
};