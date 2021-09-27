class Solution {
private:
    const string letterMap[10]{
        "",//0
        "",//1
        "abc",//2
        "def",//3
        "ghi",//4
        "jkl",//5
        "mno",//6
        "pqrs",//7
        "tuv",//8
        "wxyz"//9
    };
public:
    string path;
    vector<string> result;
    //index是digits的索引，即是digits的第几个字符
    void backtracking(const string& digits,int index){
        if(index == digits.size()){
            result.push_back(path);
            return;
        }
        //digit是第index个字符的int型，通过digit对应查找字母
        int digit = digits[index]-'0';
        //数字对应的字符集
        string letters = letterMap[digit];
        for(int i=0;i<letters.size();i++){
            path.push_back(letters[i]);
            backtracking(digits,index+1);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0){
            return result;
        }
        backtracking(digits,0);
        return result;
    }
};