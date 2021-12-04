class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result; //最终结果数组

        int startIndex = 0; //头指针
        int endIndex = numbers.size() - 1;  //尾指针

        for(int i = 0;i<numbers.size();i++){

            //如果头尾指针指向的元素和大于目标值，则移动尾指针
            if(numbers[startIndex]+numbers[endIndex]>target){
                endIndex--;

            //如果头尾指针指向的元素和小于目标值，则移动头指针
            }else if(numbers[startIndex]+numbers[endIndex]<target){
                startIndex++;

            //如果头尾指针指向的元素和等于目标值，将头尾指针push进结果数组中
            }else{
                result.push_back(startIndex+1);
                result.push_back(endIndex+1);
                break;
            }
        }
        return result;
    }
};