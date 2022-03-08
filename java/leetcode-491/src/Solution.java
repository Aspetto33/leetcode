import java.util.*;

public class Solution {
    private List<Integer> path = new ArrayList<>();
    private List<List<Integer>> result = new ArrayList<List<Integer>>();
    private Set<List<Integer>> uset = new HashSet<>();
    public List<List<Integer>> findSubsequences(int[] nums) {
        BackTracking(nums,0);

        for(List<Integer> list : uset){
            result.add(list);
        }

        return result;
    }

    public void BackTracking(int[] nums,int startIndex){

        //终止条件，当list中的元素大于1个时
        if(path.size() > 1){
            uset.add(new ArrayList<>(path));
            return;
        }

        //回溯过程
        for(int i = startIndex;i < nums.length;i++){

            if(!path.isEmpty() && nums[i] < path.get(path.size()-1))
                continue;

            path.add(nums[i]);
            BackTracking(nums,startIndex+1);
            path.remove(path.size()-1);
        }
    }
}
