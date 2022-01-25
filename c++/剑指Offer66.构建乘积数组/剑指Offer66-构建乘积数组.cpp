class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        if(a.size() == 0) return a;
        int s = a.size();

        vector<int> result(s,1);
        int tmp = 1;

        for(int i = 1;i<s;i++){
            result[i] = result[i-1]*a[i-1];

        }

        for(int i = s-2;i>=0;i--){
            tmp = tmp*a[i+1];
            result[i] = tmp*result[i];
        }
        return result;
    }
};