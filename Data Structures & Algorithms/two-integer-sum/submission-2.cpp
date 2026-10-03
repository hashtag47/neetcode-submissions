class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> val_idx;
        for(int i = 0; i < nums.size(); ++i) {
            int val = target - nums[i];
            if(val_idx.contains(val)) {
                return {val_idx[val], i};
            }
            val_idx[nums[i]] = i;
        }
        return {};
    }
};
