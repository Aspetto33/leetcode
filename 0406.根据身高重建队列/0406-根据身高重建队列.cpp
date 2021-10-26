class Solution {
public:
    //�Զ���Ƚ��㷨������ά����ĵ�һ��Ԫ�����ʱ�����յڶ���Ԫ�ش�С��������
    //����һ��Ԫ�ز����ʱ�����յ�һ��Ԫ�شӴ�С����������֤ÿ����ǰ����������ڵ��ڴ�����֮����
    //�ڶ���Ԫ�ص�ֵ�����������
    static bool cmp(const vector<int> a,const vector<int> b){
        if(a[0]==b[0]) return a[1]<b[1];
        return a[0]>b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),cmp);  //�Զ�ά���鰴���Զ�������������
        vector<vector<int>> queue;  
        for(int i=0;i<people.size();i++){
            int position = people[i][1];    //��¼��i��Ԫ�ص�hֵ
            queue.insert(queue.begin()+position,people[i]); //��people�����i��Ԫ�ز���ָ��λ��
        }
        return queue;
    }
};