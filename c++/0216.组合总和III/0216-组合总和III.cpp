class Solution {
public:
    vector<int> path;
    vector<vector<int>> result;
    void backtracking(int k,int n,int startIndex){
        //��ֹ����
        if(path.size()==k&&n==0){
            result.push_back(path);
            return;
        }
        //��������߼�
        for(int i=startIndex;i<=9;i++){
            n-=i;
            path.push_back(i);
            backtracking(k,n,i+1);
            n+=i;
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(k,n,1);
        return result;
    }
};