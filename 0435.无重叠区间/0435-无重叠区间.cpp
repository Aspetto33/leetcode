class Solution {
public:
    //��������ÿ��Ԫ�ص��������С��������
    static bool cmp(const vector<int>& a,const vector<int>& b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size()==0) return 0;   //�������û��Ԫ��ֱ�ӷ���0
        sort(intervals.begin(),intervals.end(),cmp);    //�����鰴�չ涨��������
        int count = 1;  //��¼�ж��ٲ��ص������飬��������ȥ���ص������鼴ΪӦ��ȥ�����ص���
        int end = intervals[0][1];  //�ӵ�һ��Ԫ�ص������俪ʼ
        for(int i = 1;i<intervals.size();i++){
            if(end<=intervals[i][0]){   //���������С�ڵ��ڵ�ǰԪ�ص�������˵�����ص���count++��ͬ
                                        //ʱ����end
                end = intervals[i][1];
                count++;
            }
        }
        return intervals.size()-count;
    }
};