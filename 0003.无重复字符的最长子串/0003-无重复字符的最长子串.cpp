class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> record;

        int leftIndex = 0;  //����������߽�ֵ
        int rightIndex = 0; //���������ұ߽�ֵ
        int result = 0; //���ֵ

        //�����ǰԪ��û���ڹ�ϣ���г��֣��ұ߽��ƶ�����Ԫ�ط����ϣ���У������Ƴ���һ��Ԫ�أ��������
        while(rightIndex<s.size()){
            if(record.end() == record.find(s[rightIndex])){
                record.insert(s[rightIndex++]);
            }else{
                record.erase(s[leftIndex++]);
            }
            result = max(result,rightIndex-leftIndex);  //ȡ��Ľ��ֵ
        }
        return result;
    }
};