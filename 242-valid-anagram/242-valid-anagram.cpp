class Solution {
public:

bool isAnagram(string s, string t) {
    int charMap[26] = { 0 };

    if (s.length() != t.length())
        return false;

    for (char ch : s) {
        charMap[ch - 'a']++;
    }

    for (char ch : t) {
        if (charMap[ch - 'a'] > 0) {
            charMap[ch - 'a']--;
        }
        else{
            return false;
        }
    }

    return true;

}
};