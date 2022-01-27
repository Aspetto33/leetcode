public class Solution {
    public static void main(String[] args) {
        int [] nums = {5};
        Solution solution = new Solution();
        System.out.println(solution.search(nums,5));
    }

    public int search(int[] nums, int target) {
        int left = 0;
        int right = nums.length;

        while(left < right){
            int mid = (left + right)/2;
            if(nums[mid] < target)
                left++;
            else if(nums[mid] > target)
                right--;
            else
                return mid;
        }
        return -1;
    }
}
