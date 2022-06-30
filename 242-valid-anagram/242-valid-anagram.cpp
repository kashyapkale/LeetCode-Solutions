class Solution {
public:
bool isAnagram(string s, string t) {
    unordered_map<char, int> charMap;
    
    if(s.length()!=t.length())
        return false;
    
    for (char ch : s) {
        charMap[ch]++;
    }

    for (char ch : t) {
        if (charMap.find(ch) != charMap.end() && charMap[ch] > 0) {
            charMap[ch]--;
        }
        else{
            return false;
        }
    }

    return true;

}
};