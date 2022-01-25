class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];   //记录之前的颜色

        //如果当前颜色和要换的颜色相同，直接返回
        if(oldColor == newColor) return image;  

        image[sr][sc] = newColor;

        int m = image.size();   //横坐标范围

        int n = image[0].size();    //纵坐标范围

        vector<int> dx = {1,0,-1,0};    //上左下右x坐标相对于给定sr值得偏移量

        vector<int> dy = {0,1,0,-1};    //上左下右y坐标相对于给定sc值的偏移量

        queue<pair<int,int>> record;    //记录当前坐标值

        record.emplace(sr,sc);  //起点横纵坐标加入队列

        while(!record.empty()){
            int mx = record.front().first;
            int my = record.front().second;

            record.pop();

            for(int i = 0;i<4;i++){
                int x = mx + dx[i];
                int y = my + dy[i];

                if(x>=0&&x<m&&y>=0&&y<n&&image[x][y] == oldColor){
                    image[x][y] = newColor;
                    record.emplace(x,y);
                 }
            }
        }
        return image;
    }
};