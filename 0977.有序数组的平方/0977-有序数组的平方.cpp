class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
       vector<int> result(nums.size(),0);
       int k=nums.size()-1;
       int i=0;
       int j=nums.size()-1;
       while(i<=j){
           if(nums[i]*nums[i]<nums[j]*nums[j]){
               result[k]=nums[j]*nums[j];
               k--;
               j--;
           }else{
               result[k]=nums[i]*nums[i];
               k--;
               i++;
           }
       }
       return result;
    }
};