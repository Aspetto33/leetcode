class Solution {
public:
    vector<string> result;

    void backTrack(string s,int k){
        if(k == s.size()){
            result.push_back(s);
            return;
        }

        backTrack(s,k+1);

        if(islower(s[k])){
            s[k] = toupper(s[k]);
            backTrack(s,k+1);
        }else if(isupper(s[k])){
            s[k] = tolower(s[k]);
            backTrack(s,k+1);
        }
    }
    vector<string> letterCasePermutation(string s) {
        backTrack(s,0);
        return result;
    }
};