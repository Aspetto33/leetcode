class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        unordered_map<int,int> map;

        for(auto num:nums){
            map[num]++;
        }

        int size = nums.size();
        for(auto m:map){
            if(m.second > size/2){
                return m.first;
            }
        }
        return -1;
    }
};