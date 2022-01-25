class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;

    //�������Ӽ����Բ�����ֹ����
    void backtracking(vector<int>& nums,int startIndex,vector<bool> used){
        result.push_back(path);
        for(int i=startIndex;i<nums.size();i++){
            //�������ظ�������֮ǰ���ù��ˣ�������������
            if(i>0 && nums[i] == nums[i-1] && used[i-1]==false){
                continue;
            }
            path.push_back(nums[i]);
            used[i]=true;
            backtracking(nums,i+1,used);
            used[i]=false;
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<bool> used(nums.size(),false);
        //ʹ��used������Ҫ���򣡣�����
        sort(nums.begin(),nums.end());
        backtracking(nums,0,used);
        return result;
    }
};