class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;

        if(matrix.size() == 0) return result;

        int rt = 0;
        int rb = matrix.size() - 1;

        int cl = 0;
        int cr = matrix[0].size() - 1;

        while(1){
            for(int i = cl;i<=cr;i++) result.push_back(matrix[rt][i]);
            if(++rt>rb) break;

            for(int i = rt;i<=rb;i++) result.push_back(matrix[i][cr]);
            if(--cr<cl) break;

            for(int i = cr;i>=cl;i--) result.push_back(matrix[rb][i]);
            if(--rb<rt) break;

            for(int i = rb;i>=rt;i--) result.push_back(matrix[i][cl]);
            if(++cl>cr) break;
        }
        return result;
    }
};