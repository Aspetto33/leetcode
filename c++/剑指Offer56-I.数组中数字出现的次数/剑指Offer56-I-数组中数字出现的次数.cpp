class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        unordered_map<int,int> map;

        for(int i = 0;i<nums.size();i++){
            map[nums[i]]++;
        }

        vector<int> result;

        for(int i = 0;i<map.size();i++){
            if(map[i] == 1){
                result.push_back(i);
            }
            else{
                continue;
            }
        }
        return result;
    }
};