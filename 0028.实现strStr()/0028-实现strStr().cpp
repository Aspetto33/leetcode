class Solution {
public:
    void getNext(int* next,const string& needle){
        // ��ʼ��
        int j=-1;
        next[0]=j;

        for(int i=1;i<needle.size();i++){
            // ǰ��׺����ͬ������
            while(j>=0&&needle[i]!=needle[j+1]){
                j=next[j];
            }
            // ǰ��׺��ͬ
            if(needle[i]==needle[j+1]){
                j++;
            }
            next[i]=j;
        }
    }
    int strStr(string haystack, string needle) {
        if(needle.size()==0){
            return 0;
        }
        
        int next[needle.size()];
        getNext(next,needle);
        int j=-1;
        for(int i=0;i<haystack.size();i++){
            // �����ַ����е��ַ���ƥ��ʱ
            while(j>=0&&haystack[i]!=needle[j+1]){
                j=next[j];
            }
            // �����ַ����е��ַ�ƥ��ʱ
            if(haystack[i]==needle[j+1]){
                j++;
            }
            if(j==(needle.size()-1)){
                return (i-needle.size()+1);
            }
        }
        // �������������haystack�ĳ���С��needle�ĳ���
        return -1;
    }
};