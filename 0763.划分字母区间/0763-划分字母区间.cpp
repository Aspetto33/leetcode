class Solution {
public:
    vector<int> partitionLabels(string s) {
        int hash[27] = {0}; //记录每个元素的最远下标
        for(int i=0;i<s.size();i++){
            hash[s[i]-'a'] = i;
        }
        vector<int> result; //记录结果
        int left = 0;   //左边界
        int right = 0;  //右边界
        for(int i = 0;i<s.size();i++){
            right = max(right,hash[s[i]-'a']);  //实时更新右边界
            //当到达了最远下标的时候
            if(right == i){
                result.push_back(right-left+1); //将划分结果含有的字母数量push进result中
                left = i+1; //移动左边界值
            }
        }
        return result;
    }
};