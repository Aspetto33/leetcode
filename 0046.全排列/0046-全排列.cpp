class Solution {
public:
    vector<int> path;
    vector<vector<int>> result;

    void backTrash(vector<int>& nums){
        if(path.size() == nums.size()){
            result.push_back(path);
            return;
        }

        for(int i = 0;i<nums.size();i++){
            if(find(path.begin(),path.end(),nums[i]) == path.end()){
                path.push_back(nums[i]);
                backTrash(nums);
                path.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        backTrash(nums);
        return result;
    }
};