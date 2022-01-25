class Solution {
public:
    static bool cmp(const vector<int>& a,const vector<int>& b){
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        if(intervals.size()==0) return result;
        
        sort(intervals.begin(),intervals.end(),cmp);    //������߽��С��������
        bool flag = false;  //��¼���һ��Ԫ���Ƿ�����
        for(int i = 1;i<intervals.size();i++){
            int start = intervals[i-1][0];
            int end = intervals[i-1][1];
            while(i<intervals.size()&&end>=intervals[i][0]){
                end = max(end,intervals[i][1]); //����������
                if(i == intervals.size()-1) flag = true;
                i++;
            }
            result.push_back({start,end});
        }
        //������һ������û�б���������
        if(flag == false){
            result.push_back({intervals[intervals.size()-1][0],intervals[intervals.size()-1][1]});
        }
        return result;
    }
};