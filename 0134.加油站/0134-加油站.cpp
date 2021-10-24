/*
 *�����ⷨ��
 *��һ��ѭ�����������ڵ�Ԫ��
 *���α�����while����ʣ��������0������������������iʱ����������
 *�������ѭ�����֮��ʣ������Ȼ���ڵ���0����������������i����ʱ����i
 *�����һ��ѭ�����������Ȼû�з��أ���˵��û�з��������ĳ����㣬���Ƿ���-1
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