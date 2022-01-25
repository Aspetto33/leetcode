class Solution {
public:
    void reverse(string& s,int begin,int end){
        for(int i = begin,j=end;i<j;i++,j--){
            swap(s[i],s[j]);
        }
    }
    void removeWords(string& s){
   int slowIndex = 0, fastIndex = 0; // �����ָ�룬��ָ��
        // ȥ���ַ���ǰ��Ŀո�
        while (s.size() > 0 && fastIndex < s.size() && s[fastIndex] == ' ') {
            fastIndex++;
        }
        for (; fastIndex < s.size(); fastIndex++) {
            // ȥ���ַ����м䲿�ֵ�����ո�
            if (fastIndex - 1 > 0
                    && s[fastIndex - 1] == s[fastIndex]
                    && s[fastIndex] == ' ') {
                continue;
            } else {
                s[slowIndex++] = s[fastIndex];
            }
        }
        if (slowIndex - 1 > 0 && s[slowIndex - 1] == ' ') { // ȥ���ַ���ĩβ�Ŀո�
            s.resize(slowIndex - 1);
        } else {
            s.resize(slowIndex); // ���������ַ�����С
        }
    }
    string reverseWords(string s) {
        removeWords(s);
        reverse(s,0,s.size()-1);
        for(int i = 0;i<s.size();i++){
            int j=i;
            while(j<s.size()&&s[j]!=' '){
                j++;
            }
            reverse(s,i,j-1);
            i=j;
        }
        return s;
    }
};