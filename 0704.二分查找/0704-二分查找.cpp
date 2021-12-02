class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;   //左索引
        int right = nums.size() - 1;    //右索引

        //循环条件必须要有等于，因为当数组只有一个元素，且target恰好是这个值时，符合条件
        while(left<=right){
            int middle = (left+right)/2;    //中间索引

            //当target小于中间索引对应值，右索引值变为中间值前面的索引
            if(target<nums[middle]){
                right = middle - 1;

            //当target大于中间索引对应值，左索引值变为中间值后面的索引
            }else if(target>nums[middle]){
                left = middle + 1;

            //恰好等于时返回
            }else{
                return middle;
            }
        }

        //没有符合条件的值，返回-1
        return -1;
    }
};