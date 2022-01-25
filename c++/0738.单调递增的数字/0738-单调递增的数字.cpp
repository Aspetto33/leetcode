class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string str_n = to_string(n);    //将数字转换为字符串
        //flag的初始值要为字符串大小，因为如果给定数字本来就是递增的话，
        //不用变9，直接返回原值即可
        int flag = str_n.size();    
        //从后向前遍历
        for(int i = str_n.size()-1; i>0;i--){
            if(str_n[i-1]>str_n[i]){
                flag = i;
                str_n[i-1]--;
            }
        }
        for(int i = flag;i<str_n.size();i++){
            str_n[i] = '9';
        }
        return stoi(str_n);
    }
};