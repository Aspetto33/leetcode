public class Solution {
    public static void main(String[] args) {
//        int[] nums = {-4,-1,0,3,10};
        int[] nums = {-7,-3,2,3,11};
        Solution solution = new Solution();
        int[] result = solution.sortedSquares(nums);
        for(int r:result){
            System.out.println(r);
        }
    }
    public int[] sortedSquares(int[] nums) {

        int[] result = new int[nums.length];
        int left = 0;
        int right = nums.length - 1;
        int k = nums.length - 1;

        while(left <= right){
            if(nums[left]*nums[left] <= nums[right]*nums[right]){
                result[k] = nums[right]*nums[right];
                k--;
                right--;
            }
            else{
                result[k] = nums[left]*nums[left];
                k--;
                left++;
            }
        }
        return result;
    }
}
