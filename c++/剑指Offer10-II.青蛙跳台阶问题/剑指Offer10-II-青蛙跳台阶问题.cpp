class Solution {
public:
    int numWays(int n) {
        if(n <=1) return 1;
        if(n == 2) return 2;

        int mod = 1000000007;
        int p = 0,q = 1,r = 2;

        for(int i =3;i<=n;i++){
            p = q;
            q = r;
            r = (p+q)%mod;
        }
        return r;
    }
};