class Solution {
public:
    vector<int> partitionLabels(string s) {
        int hash[27] = {0}; //��¼ÿ��Ԫ�ص���Զ�±�
        for(int i=0;i<s.size();i++){
            hash[s[i]-'a'] = i;
        }
        vector<int> result; //��¼���
        int left = 0;   //��߽�
        int right = 0;  //�ұ߽�
        for(int i = 0;i<s.size();i++){
            right = max(right,hash[s[i]-'a']);  //ʵʱ�����ұ߽�
            //����������Զ�±��ʱ��
            if(right == i){
                result.push_back(right-left+1); //�����ֽ�����е���ĸ����push��result��
                left = i+1; //�ƶ���߽�ֵ
            }
        }
        return result;
    }
};