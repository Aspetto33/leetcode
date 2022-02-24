
public class Solution {
    public int reorder (int[] prices) {
        // write code here
        int result = 0;

        if(prices.length % 2 == 1){
            for(int i = 0;i<prices.length;i++){
                if(i % 2 == 1)
                    result++;
            }
        }
        else{
            int tmp = prices.length / 2;
            result = tmp - 1;
        }

        return result;
    }
}
