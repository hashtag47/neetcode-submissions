class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> val_idx;
        for(int i = 0; i < nums.size(); ++i) {
            auto find = val_idx.find(target - nums[i]);
            if(find != val_idx.end()){
                return {find->second, i};
            }
            val_idx[nums[i]] = i;
        }
        return {};
    }
};
