class Solution {
public:
    bool isStraight(vector<int>& nums) {
        int tmp = 0;
        
        sort(nums.begin(),nums.end());

        for(int i = 1;i<nums.size();i++){
            if(nums[i-1] == 0) continue;

            if(nums[i-1] == nums[i]) return false;

            tmp += nums[i] - nums[i-1];
        }
        return tmp<5;
    }
};