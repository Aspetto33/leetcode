class Solution {
public:
    int fib(int n) {
        if(n == 0 || n == 1) return n;

        int mod = 1000000007;
        int p = 0,q = 0,r = 1;

        for(int i = 2;i<=n;i++){
            p = q;
            q = r;
            r = (p+q)%mod;
        }
        return r;
    }
};