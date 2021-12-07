class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size()<s1.size()) return false;

        vector<int> cnt1(26,0); //记录s1每个字符有多少
        vector<int> cnt2(26,0); //记录s2每个字符有多少

        //因为排列字符数量不变，所以将大小设为s1的大小
        for(int i = 0;i<s1.size();i++){
            cnt1[s1[i]-'a']++;
            cnt2[s2[i]-'a']++;
        }

        //如果两个数组相等，则返回true
        if(cnt1 == cnt2){
            return true;
        }

        //如果不相等，则移动滑动窗口，将后面的元素加入，将第一个元素移除
        for(int i = s1.size();i<s2.size();i++){
            cnt2[s2[i]-'a']++;
            cnt2[s2[i-s1.size()]-'a']--;

            if(cnt1 == cnt2){
                return true;
            }
        }

        return false;
    }
};