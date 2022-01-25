class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
          if(nums.size()<4){
              return result;
          }
          
          for (int k = 0; k < nums.size()-3; k++) {
            // ���ּ�֦�Ǵ���ģ������Ŀtarget ������ֵ
            // if (nums[k] > target) {
            //     return result;
            // }
            // ȥ��
            if(nums[k]>=1000000000){
                return {};
            }
            if (k > 0 && nums[k] == nums[k - 1]) {
                continue;
            }
            for (int i = k + 1; i < nums.size()-2; i++) {
                // ��ȷȥ�ط���
                if (i > k + 1 && nums[i] == nums[i - 1]) {
                    continue;
                }
                int left = i + 1;
                int right = nums.size() - 1;
                while (right > left) {
                    if (nums[k] + nums[i] + nums[left] + nums[right] > target) {
                        right--;
                    } else if (nums[k] + nums[i] + nums[left] + nums[right] < target) {
                        left++;
                    } else {
                        result.push_back(vector<int>{nums[k], nums[i], nums[left], nums[right]});
                        // ȥ���߼�Ӧ�÷����ҵ�һ����Ԫ��֮��
                        while (right > left && nums[right] == nums[right - 1]) right--;
                        while (right > left && nums[left] == nums[left + 1]) left++;

                        // �ҵ���ʱ��˫ָ��ͬʱ����
                        right--;
                        left++;
                    }
                }

            }
        }
        return result;
    }
};