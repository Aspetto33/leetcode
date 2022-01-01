class Solution {
private:
    static bool compare(const int& a,const int& b){
        return a<b;
    }
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end(),compare);

        vector<int> result;
        for(int i = 0;i<k;i++){
            result.push_back(arr[i]);
        }
        
        return result;
    }
};