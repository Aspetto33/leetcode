class Solution {
public:
    //递归求斐波那契数值，递归求前面两个数相加即可
    int fib(int n) {
        if(n == 0 || n == 1){
            return n;
        }
        return fib(n-1)+fib(n-2);
    }
};