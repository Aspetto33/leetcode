import static java.lang.Math.min;

public class Solution {
    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] nums = {2,3,1,2,4,3};
        System.out.println(solution.minSubArrayLen(7,nums));
    }
    public int minSubArrayLen(int target, int[] nums) {
        //数组长度为0，直接返回0
        if(nums.length == 0)
            return 0;

        int start = 0;  //滑动窗口起点
        int end = 0;    //滑动窗口终点
        int result = Integer.MAX_VALUE; //滑动窗口长度
        int sum = 0;    //滑动窗口元素总和

        while(end < nums.length){

            sum += nums[end];

            while(sum >= target){
                result = min(result,end-start+1);
                sum -= nums[start];
                start++;
            }

            end++;
        }
        return result == Integer.MAX_VALUE ? 0 : result;
    }
}
