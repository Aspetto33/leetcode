class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cover = 0;  //记录每个地方可以走的最大步数
        for(int i=0;i<=cover;i++){
            //因为当前已经在i位置了，所以要加上i判断当前位置可以往后走的步数是否可以到达终点
            cover = max(i+nums[i],cover);
            if(cover>=nums.size()-1){
                return true;
            }
        }
        return false;
    }
};