class Solution {
public:
    double myPow(double x, int n) {
        
        if(x == 0) return 0;

        if(x == 1) return 1;

        if(n == 0) return 1;

        if(n == -1) return 1/x;

        //Å¼Êý´ÎÃÝ
        if(n%2 == 0){
            return myPow(x*x,n>>1);
        } 
        else{
            return myPow(x*x,n>>1)*x;
        }
    }
};