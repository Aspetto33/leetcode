class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,0)); //��ʼ������Ԫ��Ϊ0

        //�����ַ���
        for(string str:strs){
            //��¼0��1������
            int zeroNums = 0,oneNums = 0;
            //�����ַ�����¼����
            for(char c:str){
                if(c=='0') zeroNums++;
                else oneNums++;
            }
            //�����������
            for(int i = m;i>=zeroNums;i--){
                for(int j = n;j>=oneNums;j--){
                    dp[i][j] = max(dp[i][j],dp[i-zeroNums][j-oneNums]+1);
                }
            }
        }
        return dp[m][n];
    }
};