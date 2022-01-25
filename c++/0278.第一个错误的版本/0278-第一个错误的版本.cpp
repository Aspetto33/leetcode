// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int result = 0; //记录结果的变量
        int middle = n/2;   //中间索引
        
        //数组分为两段的第一段
        for(int i = 0;i<=middle;i++){
            if(isBadVersion(i) == 1){
                result = i;
                break;
            }
        }

        //如果前半段没有找到，则寻找后面一段
        if(result == 0){
            for(int i = middle+1;i<=n;i++){
                if(isBadVersion(i) == 1){
                    result = i;
                    break;
                }
            }
        }
        return result;
    }
};