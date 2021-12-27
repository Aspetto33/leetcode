class Solution {
public:
    int strToInt(string str) {
        if(str.empty()) return 0;

        if(str[0]>='a' && str[0]<='z') return 0;

        int max = pow(2,31)-1;
        int min = -pow(2,31);

        long res = 0;
        int signal = 1;
        int i = 0;

        while(str[i]==' ')
            i++;
        
        if(str[i] == '-'){
            signal = -1;
            i++;
        }
        else if(str[i] == '+'){
            i++;
        }

        while(i<str.size()){
            if(str[i]>='0' && str[i]<='9'){
                res = res*10 + signal*(str[i]-'0');

                if(res>max){
                    return max;
                }
                else if(res<min){
                    return min;
                }
            }else{
                return res;
            }
            i++;
        }
        return res;
    }
};