import java.util.*;

public class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {

        List<Integer> list = new ArrayList<>();

        if(nums.length == 0)
            return list;

        Map<Integer,Integer> map = new HashMap<>();

        for(int num : nums){
            if(!map.containsKey(num)){
                map.put(num,1);
            }
            else{
                map.put(num,map.get(num)+1);
            }
        }

        for(int i = 1;i <= nums.length;i++){
            if(!map.containsKey(i)){
                list.add(i);
            }
        }
        return list;
    }
}
