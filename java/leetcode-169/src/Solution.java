import java.util.HashMap;
import java.util.Map;

public class Solution {
    public int majorityElement(int[] nums) {
        Map<Integer,Integer> map = new HashMap<Integer,Integer>();
        int count = 0;

        for(int num : nums){

            if(!map.containsKey(num)){
                map.put(num,1);
            }
            else{
                map.put(num,map.get(num)+1);
            }
        }

        for(Map.Entry<Integer,Integer> map1:map.entrySet()){
            if(map1.getValue() > nums.length / 2)
                return map1.getKey();
        }
        return 0;
    }
}
