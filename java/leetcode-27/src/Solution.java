public class Solution {
    public static void main(String[] args) {
        int[] nums = {3,2,2,3};
        Solution solution = new Solution();
        System.out.println(solution.removeElement(nums,3));
    }
    public int removeElement(int[] nums, int val) {

        int left = 0;
        for(int right = 0;right < nums.length;right++){

            if(nums[right] != val){
                nums[left] = nums[right];
                left++;
            }
        }
        return left;
    }
}
