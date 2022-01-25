class Solution {
public:
    /*
     *不开辟多余空间，考虑异或。
     *0和其他所有数异或均为此数本身
     *数本身异或结果为0
    */
    int singleNumber(vector<int>& nums) {
        int result = 0;
        
        //异或
        for(int num:nums){
            result = result^num;
        }

        return result;
    }
};