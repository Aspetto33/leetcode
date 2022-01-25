class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;   //左索引
        int right = nums.size()-1;  //右索引
        while(left<=right){
            int middle =(left+right)/2;
            if(target<=nums[middle]){
                right = middle-1;
            }else{
                left = middle+1;
            }
        }
        return left;    //当到left>right的时候循环停止，因此返回left
    }
};