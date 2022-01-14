class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> result;
        int target = pow(10,n);

        for(int i = 1;i<target;i++){
            result.push_back(i);
        }

        return result;
    }
};