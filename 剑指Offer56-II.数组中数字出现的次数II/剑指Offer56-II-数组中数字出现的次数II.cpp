class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        unordered_map<int,int> map;

        for(auto num:nums){
            map[num]++;
        }

        for(auto m:map){
            if(m.second == 1){
                return m.first;
            }
        }
        return -1;
    }
};