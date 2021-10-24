/*
 *暴力解法：
 *第一重循环遍历数组内的元素
 *环形遍历用while，当剩余量大于0并且所在索引不等于i时，遍历继续
 *如果二重循环完成之后剩余量仍然大于等于0并且所在索引等于i，此时返回i
 *如果第一重循环遍历完后仍然没有返回，则说明没有符合条件的出发点，于是返回-1
*/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for(int i=0;i<gas.size();i++){
            int rest = gas[i]-cost[i];
            int index = (i+1)%gas.size();
            while(rest>0&&index!=i){
                rest+=gas[index]-cost[index];
                index=(index+1)%gas.size();
            }
            if(rest>=0&&index==i) return i;
        }
        return -1;
    }
};