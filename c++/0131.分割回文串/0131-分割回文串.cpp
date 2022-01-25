class Solution {
private:
    vector<vector<string>> result;
    vector<string> path;

    void backtracking(const string& s,int startIndex){
        //终止条件,本题中startIndex作为切割线,当startIndex到字符串的最后时，即结束
        if(startIndex>=s.size()){
            result.push_back(path);
            return;
        }
        for(int i=startIndex;i<s.size();i++){
            if(isPalindrome(s,startIndex,i)){
                string str = s.substr(startIndex,i-startIndex+1);
                path.push_back(str);
            }else{
                continue;
            }
            backtracking(s,i+1);
            path.pop_back();
        }
    }

    bool isPalindrome(const string& s,int start,int end){
        for(int i=start,j=end;i<j;i++,j--){
            if(s[i]!=s[j]){
                return false;
            }
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        backtracking(s,0);
        return result;
    }
};