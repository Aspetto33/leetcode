class Solution {
public:
    void getNext(int* next,const string& s){
        // 初始化
        int j=-1;
        next[0]=j;
        for(int i=1;i<s.size();i++){
            // 不匹配时，回退
            while(j>=0&&s[i]!=s[j+1]){
                j=next[j];
            }
            if(s[i]==s[j+1]){
                j++;
            }
            next[i]=j;
        }
    }
    bool repeatedSubstringPattern(string s) {
        int next[s.size()];
        getNext(next,s);
        int len = s.size();
        if(next[len-1]!=-1&&len%(len-next[len-1]-1)==0){
            return true;
        }
        return false;
    }
};