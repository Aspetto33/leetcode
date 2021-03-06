class Solution {
public:
    int getSum(int n){
        int sum = 0;
        while(n){
            sum+=(n%10)*(n%10);
            n/=10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int sum = getSum(n);
        unordered_set<int> result;
        while(1){
            if(sum==1){
                return true;
            }
            if(result.find(sum)!=result.end()){
                return false;
            }else{
                result.insert(sum);
            }
            sum=getSum(sum);
        }
    }
};