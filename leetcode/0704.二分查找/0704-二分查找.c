int search(int* nums, int numsSize, int target){
    int left = 0;
    int right = numsSize-1;
    int middle = left + ((right-left)/2);
    while(left<=right){
        if(nums[middle] == target){
            return middle;
        }else if(nums[middle]>target){
            right = middle-1;
            middle = left+((right-left)/2);
        }else{
            left = middle+1;
            middle = left+((right-left)/2);
        }
    }
    return -1;
}