class Solution {
private:
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // int dists[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> dist(m,vector<int>(n));

        vector<vector<int>> visted(m,vector<int>(n));

        queue<pair<int,int>> que;

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(mat[i][j] == 0){
                    que.emplace(i,j);
                    visted[i][j] = 1;
                }
            }
        }

        while(!que.empty()){
            auto [mx,my] = que.front();
            que.pop();
            for(int index = 0;index<4;index++){
                int x = mx + dirs[index][0];
                int y = my + dirs[index][1];

                if(x>=0&&x<mat.size()&&y>=0&&y<mat[0].size()&&!visted[x][y]){
                    dist[x][y]=dist[mx][my] + 1;
                    que.emplace(x,y);
                    visted[x][y] = 1;
                } 
            }
        }

        return dist;
    }
};