class Solution {
public:
    int findNthDigit(int n) {
        int m=10;int i=2;
            if(n<10) return n; 
            for(;i<9;i++){
                int now=pow(10,i-1)*9*i;
                if(m+now>n) break;
                m+=now;
            }
            int start=pow(10,i-1);//10
            int remain= n-m;//11-10=1
            int now=start+remain/i;//10+0=10
            int index=remain%i;
            string num=to_string(now);
            return num[index]-'0';
    }
};