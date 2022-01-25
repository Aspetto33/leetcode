class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];   //��¼֮ǰ����ɫ

        //�����ǰ��ɫ��Ҫ������ɫ��ͬ��ֱ�ӷ���
        if(oldColor == newColor) return image;  

        image[sr][sc] = newColor;

        int m = image.size();   //�����귶Χ

        int n = image[0].size();    //�����귶Χ

        vector<int> dx = {1,0,-1,0};    //��������x��������ڸ���srֵ��ƫ����

        vector<int> dy = {0,1,0,-1};    //��������y��������ڸ���scֵ��ƫ����

        queue<pair<int,int>> record;    //��¼��ǰ����ֵ

        record.emplace(sr,sc);  //����������������

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