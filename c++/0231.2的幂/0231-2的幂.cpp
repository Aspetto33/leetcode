class Solution {
public:
    bool isPowerOfTwo(int n) {
        //n等于0的时候不符合条件，返回false
        if(n == 0) return false;

        //n等于1的时候符合条件
        if(n == 1) return true;

        //当n不等于1的时候循环，如果n除以2的余数不为0，终止循环
        while(n!=1){
            if(n%2!=0) break;
            n = n/2;
            // cout<<i;
        }

        if(n!=1) return false;
        return true;
    }
};