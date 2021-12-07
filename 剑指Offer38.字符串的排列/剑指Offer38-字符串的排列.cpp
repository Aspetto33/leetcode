class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size()<s1.size()) return false;

        vector<int> cnt1(26,0); //��¼s1ÿ���ַ��ж���
        vector<int> cnt2(26,0); //��¼s2ÿ���ַ��ж���

        //��Ϊ�����ַ��������䣬���Խ���С��Ϊs1�Ĵ�С
        for(int i = 0;i<s1.size();i++){
            cnt1[s1[i]-'a']++;
            cnt2[s2[i]-'a']++;
        }

        //�������������ȣ��򷵻�true
        if(cnt1 == cnt2){
            return true;
        }

        //�������ȣ����ƶ��������ڣ��������Ԫ�ؼ��룬����һ��Ԫ���Ƴ�
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