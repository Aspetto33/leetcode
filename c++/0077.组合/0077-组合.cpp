class Solution {
public:
    vector<int> path;
    vector<vector<int>> result;

    void backTrash(int startIndex,int n,int k){
        if(path.size() == k){
            result.push_back(path);
            return;
        }

        for(int i = startIndex;i<=n;i++){
            path.push_back(i);
            backTrash(i+1,n,k);
            path.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        backTrash(1,n,k);
        return result;
    }
};