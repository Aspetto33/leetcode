import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class Solution {
    public int[] twoSum(int[] nums, int target) {

        int[] result = new int[2];

        if(nums == null || nums.length == 0)
            return result;

        Map map = new HashMap<>();

        for(int i = 0;i < nums.length;i++){
            int tmp = target - nums[i];

            if(map.containsKey(tmp)){
                result[0] = i;
                result[1] = (int) map.get(tmp);
            }
            else{
                map.put(nums[i],i);
            }
        }
        return result;
    }
}
