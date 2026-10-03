class Solution {
public:
    bool isAnagram(string s, string t) {
       if(s.size() != t.size()) {
        return false;
       }
       //letters in utf-8 and ascii are consecutive
       int atoz[26] = {0};
       for(char tmp: s) ++atoz[tmp - 'a'];
       for(char tmp: t) --atoz[tmp - 'a'];
       for(int i: atoz) {
        if(i != 0) {
            return false;
        }
       }
       return true;
    }
};
