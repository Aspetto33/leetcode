class Solution {
public:
    //交换函数
    void swap(char& a,char& b){
        char tmp;

        tmp = a;
        a = b;
        b = tmp;
    }
    string reverseWords(string s) {
        int slowIndex = 0;  //快指针
        int fastIndex = 0;  //慢指针

        //交换循环条件是快指针不超过s的长度
        while(fastIndex<s.size()){

            //移动快指针到单词的空格处
            while(fastIndex<s.size()&&s[fastIndex]!=' '){
                fastIndex++;
            }

            int fastIndex1 = fastIndex - 1; //单词尾部

            //反转单词
            while(slowIndex<fastIndex1){
                swap(s[slowIndex],s[fastIndex1]);
                slowIndex++;
                fastIndex1--;
            }
            fastIndex++;    //快指针到下个单词的头部

            //移动慢指针到下个单词的头部
            while(slowIndex<s.size()&&s[slowIndex]!=' '){
                slowIndex++;
            }
            slowIndex++;
        }
        return s;
    }
};