class Solution {
public:
    vector<int> path;   //记录当前符合条件的组合
    vector<vector<int>> result; //记录最终结果

    void backtracking(vector<int>& candidates,int target,int startIndex,vector<bool>& used){
        //当target小于0时，即组合的和大于target时，程序终止
        if(target<0){
            return;
        }
        //当target等于0的时候，将当前符合条件的组合push进最终结果数组中
        if(target==0){
            result.push_back(path);
            return;
        }
        //横向遍历candidates数组，纵向递归。
        for(int i = startIndex;i<candidates.size();i++){
            //去重
            if(i>0&&candidates[i]==candidates[i-1]&&used[i-1] ==false){
                continue;
            }
            path.push_back(candidates[i]);
            target-=candidates[i];
            used[i] = true;
            backtracking(candidates,target,i+1,used);
            used[i] = false;
            target+=candidates[i];  //target回溯
            path.pop_back();    //path回溯
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<bool> used(candidates.size(),false);
         //排序
        sort(candidates.begin(),candidates.end());
        backtracking(candidates,target,0,used);
        return result;
    }
};