class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> val_idx;
        for(std::size_t i = 0; i < nums.size(); ++i) {
            auto find = val_idx.find(target - nums[i]);
            if(find != val_idx.end()){
                return {find->second, static_cast<int>(i)};
            }
            val_idx[nums[i]] = i;
        }
        return {};
    }
};
