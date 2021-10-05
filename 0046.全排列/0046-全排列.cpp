class Solution {
/*
 *ȫ��������˳��ģ���ͬ�ڼ��ϣ������Ҫ��һ������������¼
 *��Щ���ù�����Щû���ù���Ȼ���û���ù�������ȡ��ֱ��path����
 *�Ĵ�С����nums����Ĵ�С��
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