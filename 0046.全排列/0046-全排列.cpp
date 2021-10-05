class Solution {
/*
 *全排列是有顺序的，不同于集合，因此需要有一个数组用来记录
 *哪些数用过，哪些没有用过，然后从没有用过的数中取，直到path数组
 *的大小等于nums数组的大小。
*/
private:
    vector<int> path;
    vector<vector<int>> result;

    void backtracking(vector<int>& nums,vector<bool>& used){
        if(path.size()==nums.size()){
            result.push_back(path);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(used[i]==true) continue;
            used[i]=true;
            path.push_back(nums[i]);
            backtracking(nums,used);
            path.pop_back();
            used[i]=false;
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(),false);
        backtracking(nums,used);
        return result;
    }
};