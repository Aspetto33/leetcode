class Solution {
public:
    vector<string> permutation(string s) {
        vector<string> result;
        dfs(result,s,0);
        return result;
    }

    void dfs(vector<string> &res,string &s,int pos){
        if(pos == s.size()){
            res.push_back(s);
        }

        for(int i = pos;i<s.size();i++){
            bool flag = true;

            for(int j = pos;j<i;j++){
                if(s[j] == s[i]) flag = false;
            }
            if(flag){
                    swap(s[pos],s[i]);
                    dfs(res,s,pos+1);
                    swap(s[pos],s[i]);  
                }
        }
    }
};