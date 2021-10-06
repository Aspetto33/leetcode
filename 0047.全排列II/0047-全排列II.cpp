class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;

    void backtracking(vector<int>& nums,vector<bool>& used){
        if(path.size()==nums.size()){
            result.push_back(path);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(i>0&&nums[i]==nums[i-1]&&used[i-1]==false){
                continue;
            }
            if(used[i]==false){
                used[i]=true;
                path.push_back(nums[i]);
                backtracking(nums,used);
                path.pop_back();
                used[i]=false;
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> used(nums.size(),false);
        sort(nums.begin(),nums.end());//���򣬽���ͬԪ�ط���һ��
        backtracking(nums,used);
        return result;
    }
};