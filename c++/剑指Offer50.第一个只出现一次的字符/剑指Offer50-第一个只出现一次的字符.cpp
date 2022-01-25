class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char,int> result;

        for(int i = 0;i<s.size();i++){
            result[s[i]]++;
        }

        for(char s1:s){
            if(result[s1] == 1) return s1;
        }

        return ' ';
    }
};