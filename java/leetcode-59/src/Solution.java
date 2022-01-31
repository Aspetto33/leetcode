public class Solution {
    public static void main(String[] args) {
        Solution solution = new Solution();
        int[][] ints = solution.generateMatrix(3);
        for (int i = 0; i < 3; i++) {
            for(int j = 0;j<3;j++){
                System.out.println(ints[i][j]);
            }
        }

    }
    public int[][] generateMatrix(int n) {

        int[][] result = new int[n][n];

        int top = 0;    //矩阵上边界
        int bottom = n-1;   //矩阵下边界
        int left = 0;   //矩阵左边界
        int right = n-1;    //矩阵右边界

        int m = 1;

        while(m<=n*n){
            for(int i = left;i<=right;i++){
                result[top][i] = m;
                m++;
            }
            top++;

            for(int i = top;i<=bottom;i++){
                result[i][right] = m;
                m++;
            }
            right--;

            for(int i = right;i>=left;i--){
                result[bottom][i] = m;
                m++;
            }
            bottom--;

            for(int i = bottom;i>=top;i--){
                result[i][left] = m;
                m++;
            }
            left++;
        }
        return result;
    }
}
