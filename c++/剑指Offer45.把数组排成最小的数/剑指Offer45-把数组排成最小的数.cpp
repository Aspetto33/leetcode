class Solution {
private:
    //按照字符串前后相加较小值排序
    static bool compare(const string& a,const string& b){
        return a+b<b+a;
    }
public:
    string minNumber(vector<int>& nums) {
        vector<string> strs;
        string result;

        for(int num:nums){
            strs.push_back(to_string(num));
        }

        sort(strs.begin(),strs.end(),compare);

        for(string str:strs){
            result += str;
        }

        return result;
    }
};