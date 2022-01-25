class Solution {
public:
    int minArray(vector<int>& numbers) {
        int minNum = numbers[0];

        int leftIndex = 0;
        int rightIndex = numbers.size()-1;

        while(leftIndex<=rightIndex){
            if(numbers[leftIndex]<numbers[rightIndex]){
                minNum = min(minNum,numbers[leftIndex]);
                leftIndex++;
            }else{
                minNum = min(minNum,numbers[rightIndex]);
                rightIndex--;
            }
        }
        return minNum;
    }
};