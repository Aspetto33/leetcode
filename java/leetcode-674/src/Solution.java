public class Solution {
    public int findLengthOfLCIS(int[] nums) {

        int result = 1;
        int[] dp = new int[nums.length];

        for(int i = 0;i < nums.length;i++){
            dp[i] = 1;
        }

        for(int i = 1;i < nums.length;i++){
            if(nums[i] > nums[i-1])
                dp[i] = dp[i-1] + 1;

            result = Math.max(result,dp[i]);
        }
        return result;
    }
}
