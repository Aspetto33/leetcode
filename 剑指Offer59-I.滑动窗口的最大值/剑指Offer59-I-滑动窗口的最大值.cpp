class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        vector<int> result;
        
        if(nums.size() == 0) return result;

        for(int i = 0;i<nums.size()-k+1;i++){
            int max = INT_MIN;
            for(int j = i;j<i+k;j++){
                if(nums[j]>max) max = nums[j];
            }
            result.push_back(max);
        } 
        return result;
    }
};