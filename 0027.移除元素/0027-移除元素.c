int removeElement(int* nums, int numsSize, int val){
    int slowIndex = 0;
    for(int fastIndex = 0;fastIndex<numsSize;fastIndex++){
        if(val!=nums[fastIndex]){
            nums[slowIndex] = nums[fastIndex];
            slowIndex++;
        }
    }
    return slowIndex;
}