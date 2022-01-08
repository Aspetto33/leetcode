class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {

        vector<vector<int>> result;

        for(int left = 1,right = 1,sum = 0;right<target;right++){
            sum += right;

            while(sum>target){
                sum -= left++;
            }

            if(sum == target){
                vector<int> path;
                for(int i = left;i<=right;i++){
                    path.push_back(i);
                }
                result.push_back(path);
                // path.clear();
            }
        }
        return result;
    }
};