class Solution {
public:
    int movingCount(int m, int n, int k) {
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(get(i,j)>k) mat[i][j] = true;
                else mat[i][j] = false;
            }
        }
        backtrack(m,n,0,0);
        return count;
    }

private:
    int count = 0;
    bool visted[100][100];
    bool mat[100][100];
    int get(int m,int n){
        int ans = 0;
        
        while(m){
            ans += m%10;
            m = m/10;
        }

        while(n){
            ans += n%10;
            n = n/10;
        }

        return ans;
    }

    void backtrack(int m,int n,int i,int j){
        if(i>=m || i<0 || j>=n || j<0 || visted[i][j] || mat[i][j]) return;
        visted[i][j] = true;
        count++;
        backtrack(m,n,i,j+1);
        backtrack(m,n,i+1,j);
    }
};