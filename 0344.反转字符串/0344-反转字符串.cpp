class Solution {
public:
    //交换a b
    void swap(char& a,char& b){
        char tmp;   

        tmp = a;
        a = b;
        b = tmp;

    }
    void reverseString(vector<char>& s) {
        
        int leftIndex = 0;  //左指针
        int rightIndex = s.size() - 1;  //右指针

        //当左指针小于右指针的时候循环交换左右指针指向的元素
        while(leftIndex<rightIndex){
            
            swap(s[leftIndex],s[rightIndex]);

            leftIndex++;    //向右移动左指针
            rightIndex--;   //向左移动右指针
        }
    }
};