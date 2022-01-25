class Solution {
public:
    int jump(vector<int>& nums) {
        int max_far = 0;    //记录当前元素指定区域可以走的最大步数
        int step = 0;   //记录到达终点走的步数
        int end = 0;   //记录当前元素指定区间的边界
        //遍历到倒数第二个元素，因为肯定可达，所以最后到达的位置一定在最后一个元素的位置或者后面
        for(int i=0;i<nums.size()-1;i++){
            max_far = max(nums[i]+i,max_far);   //不断对比区间内哪个元素更大
            //如果指针i走到区域边界，step需要加1
            if(i == end){
                step++;
                end = max_far;
            }
        }
        return step;
    }
};