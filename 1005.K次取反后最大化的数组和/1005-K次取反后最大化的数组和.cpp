/*
 *  首先将数组按照绝对值大小从大到小排序
 *  然后将值小于0的数变为正值并且将k减1
 *  如果最后k剩下的是偶数，相当于剩下的正数从正数变为负数再变为正数，因此可以不用管
 *  如果剩下的是奇数，则将排序之后的数组最后一个元素变为负数
*/
class Solution {
static bool cmp(int a,int b){
    return abs(a)>abs(b);
}
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end(),cmp);
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0&&k>0){
                nums[i]*=-1;
                k--;
            }
        }
        if(k%2==1) nums[nums.size()-1]*=-1; //如果k为奇数，则将最小的值变为负数
        int result = 0; //记录最后的和
        for(int num:nums){
            result+=num;
        }
        return result;
    }
};