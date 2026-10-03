class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //anagrms is just same letters plus same size
        std::unordered_map<std::string, std::vector<std::string>> str_svec;
        for(const string& s: strs) {
            std::string ss = s;
            std::sort(ss.begin(), ss.end());
            str_svec[ss].push_back(s);
        }

        std::vector<std::vector<std::string>> res;
        for(const auto& strvec: str_svec) {
            //std::vector supports move semantics
            res.push_back(std::move(strvec.second));
        }
        return res;
    }
};
