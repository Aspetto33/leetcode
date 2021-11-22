class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0 ) return 0;
        if(nums.size()==1 ) return nums[0];
        
        int result1 = robRange(nums,0,nums.size()-2);   //����ʹ��ͷԪ�أ���ʹ��βԪ��
        int result2 = robRange(nums,1,nums.size()-1);   //����ʹ��βԪ�أ���ʹ��ͷԪ��
        cout<<result1<<endl;
        cout<<result2<<endl;
        return max(result1,result2);
    }

    int robRange(vector<int>& nums,int start,int end){
        if(end == start) return nums[start];
        vector<int> dp(nums.size());
        dp[start] = nums[start];
        cout<<"�׸�Ԫ�أ�"<<dp[start]<<endl;
        dp[start+1] = max(nums[start],nums[start+1]);
        cout<<"�ڶ���Ԫ�أ�"<<dp[start+1]<<endl;

        for(int i = start+2;i<=end;i++){
            dp[i] = max(dp[i-2]+nums[i],dp[i-1]);
        }
        return dp[end];
    }
};