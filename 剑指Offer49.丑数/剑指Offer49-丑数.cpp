class Solution {
public:
    int nthUglyNumber(int n) {

        vector<int> result(n,0);
        result[0] = 1;

        int i = 0,j = 0,k = 0;
        for(int index = 1;index<n;index++){
            int tmp = min(result[i]*2,min(result[j]*3,result[k]*5));

            if(tmp == result[i]*2) i++;
            if(tmp == result[j]*3) j++;
            if(tmp == result[k]*5) k++;

            result[index] = tmp;
        }

        return result[n-1];
    }
};