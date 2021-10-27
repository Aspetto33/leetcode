class Solution {
public:
    //将二维数组按照points[i][0]排序
    static bool cmp(const vector<int>& a,const vector<int>& b){
        return a[0]<b[0];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size()==0) return 0;  //数组为空直接返回0
        sort(points.begin(),points.end(),cmp);
        int result = 1; //数组不为空至少需要一只箭，所以result初始值为1
        for(int i=1;i<points.size();i++){
            if(points[i][0]>points[i-1][1]){    //如果当前i的左边界大于前一个元素的右边界，需要一只
                result++;
            }else{
                points[i][1] = min(points[i-1][1],points[i][1]);    //更新最小右边界
            }
        }
        return result;
    }
};