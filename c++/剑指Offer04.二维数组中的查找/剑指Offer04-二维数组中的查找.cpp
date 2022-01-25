class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {

        if(matrix.size() == 0) return false;

        int n = matrix.size();
        int m = matrix[0].size();

        int row = 0;
        int column = m-1;

        while(row<n && column>=0){
            if(matrix[row][column]<target){
                row++;
            }else if(matrix[row][column]>target){
                column--;
            }else{
                return true;
            }
        }
        return false;
    }
};