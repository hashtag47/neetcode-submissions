class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        //We don't want to keep the original order
        std::sort(nums.begin(), nums.end(), std::less<int>());
        for(std::size_t i = 1; i < nums.size(); ++i) {
            if(nums[i] == nums[i-1]) {
                return true;
            }
        }
        return false;
    }
};