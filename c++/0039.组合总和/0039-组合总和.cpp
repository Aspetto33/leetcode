class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(vector<int>& candidates,int target,int startIndex){
        if(target<0){
            return;
        }
        if(target==0){
            result.push_back(path);
        }
        for(int i=startIndex;i<candidates.size();i++){
            path.push_back(candidates[i]);
            target-=candidates[i];
            backtracking(candidates,target,i);//表示可以重复取值
            target+=candidates[i];//回溯
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtracking(candidates,target,0);
        return result;
    }
};