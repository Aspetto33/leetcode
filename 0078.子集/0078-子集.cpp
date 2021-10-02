class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;
    //因为是取所有的子集，因此可以不用加终止条件，当startIndex大于num.size()时，便已终止
    void backtracking(vector<int>& nums,int startIndex){
        for(int i=startIndex;i<nums.size();i++){
            path.push_back(nums[i]);
            backtracking(nums,i+1);
            path.pop_back();
        }
        result.push_back(path);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        backtracking(nums,0);
        return result;
    }
};