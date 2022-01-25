class Solution {
public:
    //自定义比较算法，当二维数组的第一个元素相等时，按照第二个元素从小到大排序
    //当第一个元素不相等时，按照第一个元素从大到小排序这样保证每个数前面的数都大于等于此数，之后按照
    //第二个元素的值插入调整即可
    static bool cmp(const vector<int> a,const vector<int> b){
        if(a[0]==b[0]) return a[1]<b[1];
        return a[0]>b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),cmp);  //对二维数组按照自定义规则进行排序
        vector<vector<int>> queue;  
        for(int i=0;i<people.size();i++){
            int position = people[i][1];    //记录第i个元素的h值
            queue.insert(queue.begin()+position,people[i]); //将people数组的i个元素插入指定位置
        }
        return queue;
    }
};