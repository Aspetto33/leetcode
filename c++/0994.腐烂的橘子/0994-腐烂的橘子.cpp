class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // vector<vector<int>> visted(grid.size(),vector<int>(grid[0].size()));

        queue<pair<int,int>> que;
        int count = 0;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j] == 1){
                    count++;
                }

                if(grid[i][j] == 2){
                    que.emplace(i,j);
                }
            }
        }

        int dx[4] = {1,0,-1,0};
        int dy[4] = {0,1,0,-1};

        int result = 0;
        while(count>0&&!que.empty()){
                result++;
                int gsize = que.size();
                cout<<gsize;
                for(int g = 0;g<gsize;g++){
                    int mx = que.front().first;
                    int my = que.front().second;

                    que.pop();
                for(int index = 0;index<4;index++){
                    int x = mx + dx[index];
                    int y = my + dy[index];

                    if(x>=0&&x<grid.size()&&y>=0&&y<grid[0].size()&&grid[x][y]==1){
                        grid[x][y] = 2;
                        que.emplace(x,y);
                        count--;
                    }
                }
                }
                
            
        }
        if(count>0) return -1;
        
        return result;
    }
};