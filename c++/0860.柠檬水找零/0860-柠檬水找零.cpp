class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if(bills[0]>5){
            return false;
        }else{
            int record5 = 0;    //记录现有的5元的数量
            int record10 = 0;   //记录现有的10元的数量
            int record20 = 0;   //记录现有的20元的数量

            //循环遍历数组，判断最后是否能全部成功找零
            for(int i=0;i<bills.size();i++){

                //当给的钱是5元时，record5加1，此时不用找零
                if(bills[i] == 5){
                    record5++;
                }

                //当给的钱是10元时，判断5元的数量，如果大于等于1，则record5减1，record10加1
                //否则返回false
                if(bills[i] == 10){
                    if(record5>=1){
                        record10++;
                        record5--;
                    }else{
                        return false;
                    }
                }

                //当给的钱是20时，优先判断是否有大于0张的10元和5元，因为10元只能给20找
                //如果有则record10和record5减1，record20加1
                //如果有三张以上的5元时，则record5-3，record20加1
                //否则返回false
                if(bills[i]==20){
                   if(record5>0&&record10>0){
                       record5--;
                       record10--;
                       record20++;
                   }else if(record5>=3){
                       record5-=3;
                       record20++;
                   }else{
                       return false;
                   }
                }
            }
        }
        return true;
    }
};