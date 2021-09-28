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
            backtracking(candidates,target,i);//��ʾ�����ظ�ȡֵ
            target+=candidates[i];//����
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtracking(candidates,target,0);
        return result;
    }
};