import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Solution {
    public List<List<Integer>> threeSum(int[] nums) {

        List<List<Integer>> result = new ArrayList();

        if(nums == null || nums.length <= 2)
            return result;

        //对数组进行排序操作
        Arrays.sort(nums);

        for(int i = 0;i<nums.length - 2;i++){

            //如果第一个数大于0，三数相加不可能为零
            if(nums[i] > 0)
                break;

            //去重
            if(i > 0 && nums[i] == nums[i-1])
                continue;

            int target = -nums[i];
            int left = i+1;
            int right = nums.length - 1;

            while(left < right){
                if(nums[left] + nums[right] == target){
                    result.add(new ArrayList<>(Arrays.asList(nums[i],nums[left],nums[right])));
                    left++;
                    right--;

                    //去重
                    while(left < right && nums[left] == nums[left-1])
                        left++

                    while(left < right && nums[right] == nums[right+1])
                        right--;
                }
                else if(nums[left] + nums[right] > target){
                    right--;
                }
                else{
                    left++;
                }
            }
        }
        return result;
    }
}
