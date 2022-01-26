

public class Solution {
    public static void main(String[] args) {
//        int[] nums = {1,1,2,3,5,6,6};
        int[] nums = {};
        Solution solution = new Solution();
        int result = solution.removeDuplicates(nums);
        System.out.println(result);
    }

    public int removeDuplicates(int[] nums) {
        if(nums.length == 0)
            return 0;
        //双指针法
        int slow = 1;
        int fast = 1;

        while(fast < nums.length){
            if(nums[fast] != nums[fast-1]){
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }
        return slow;
    }
}
