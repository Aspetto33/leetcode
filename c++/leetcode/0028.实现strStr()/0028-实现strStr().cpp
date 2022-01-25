class Solution {
public:
    void getNext(int* next,const string& needle){
        // 初始化
        int j=-1;
        next[0]=j;

        for(int i=1;i<needle.size();i++){
            // 前后缀不相同，回退
            while(j>=0&&needle[i]!=needle[j+1]){
                j=next[j];
            }
            // 前后缀相同
            if(needle[i]==needle[j+1]){
                j++;
            }
            next[i]=j;
        }
    }
    int strStr(string haystack, string needle) {
        if(needle.size()==0){
            return 0;
        }
        
        int next[needle.size()];
        getNext(next,needle);
        int j=-1;
        for(int i=0;i<haystack.size();i++){
            // 两个字符串中的字符不匹配时
            while(j>=0&&haystack[i]!=needle[j+1]){
                j=next[j];
            }
            // 两个字符串中的字符匹配时
            if(haystack[i]==needle[j+1]){
                j++;
            }
            if(j==(needle.size()-1)){
                return (i-needle.size()+1);
            }
        }
        // 其他情况，诸如haystack的长度小于needle的长度
        return -1;
    }
};