class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;

    void backtracking(vector<int>& nums,int startIndex){
        unordered_set<int> uset;
        //��ֹ����
        if(path.size()>1){
            result.push_back(path);
            //����дreturn����Ϊ�������е���������
        }
        //����ѭ���߼�
        for(int i=startIndex;i<nums.size();i++){
            //ȥ��
        if ((!path.empty() && nums[i] < path.back())
            || uset.find(nums[i]) != uset.end()) {
            continue;
        }
            //��¼�Ѿ�ʹ�ù���Ԫ�أ�ͬһ���в�����ʹ��
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