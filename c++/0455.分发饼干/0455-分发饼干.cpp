class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int result=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        //饼干的最后元素的索引值
        int index = s.size()-1;
        for(int i=g.size()-1;i>=0;i--){
            //判断index>=0可以保证没有空指针异常
            if(index>=0&&s[index]>=g[i]){
                result++;
                index--;
            }
        }
        return result;
    }
};