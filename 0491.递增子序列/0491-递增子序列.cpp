class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;

    void backtracking(vector<int>& nums,int startIndex){
        unordered_set<int> uset;
        //终止条件
        if(path.size()>1){
            result.push_back(path);
            //不能写return，因为是求所有递增子序列
        }
        //单层循环逻辑
        for(int i=startIndex;i<nums.size();i++){
            //去重
        if ((!path.empty() && nums[i] < path.back())
            || uset.find(nums[i]) != uset.end()) {
            continue;
        }
            //记录已经使用过的元素，同一层中不能再使用
            uset.insert(nums[i]);
            path.push_back(nums[i]);
            backtracking(nums,i+1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtracking(nums,0);
        return result;
    }
};