class Solution {
public:
    //按照数组每个元素的右区间从小到大排序
    static bool cmp(const vector<int>& a,const vector<int>& b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size()==0) return 0;   //如果数组没有元素直接返回0
        sort(intervals.begin(),intervals.end(),cmp);    //对数组按照规定规则排序
        int count = 1;  //记录有多少不重叠的数组，用总数减去不重叠的数组即为应该去除的重叠数
        int end = intervals[0][1];  //从第一个元素的右区间开始
        for(int i = 1;i<intervals.size();i++){
            if(end<=intervals[i][0]){   //如果右区间小于等于当前元素的左区间说明不重叠，count++，同
                                        //时右移end
                end = intervals[i][1];
                count++;
            }
        }
        return intervals.size()-count;
    }
};