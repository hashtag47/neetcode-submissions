class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> str_svec;
        for(const auto& s: strs) {
            std::string ss{s};
            std::sort(ss.begin(), ss.end());
            str_svec[ss].push_back(std::move(s));
        }
        std::vector<std::vector<std::string>> res;

        for(const auto& [str, vec] : str_svec) {
            res.push_back(std::move(vec));
        }
        return res;
    }
};
