class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;
    //��Ϊ��ȡ���е��Ӽ�����˿��Բ��ü���ֹ��������startIndex����num.size()ʱ��������ֹ
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