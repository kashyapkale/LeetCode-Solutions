class Solution {
public:

bool isAnagram(string s, string t) {
    int charMap[26] = { 0 };

    if (s.length() != t.length())
        return false;

    for(int i = 0;i<s.length();i++){
        charMap[s[i] - 'a']++;
        charMap[t[i] - 'a']--;
    }

    for (char ch : t) {
        if (charMap[ch - 'a'] < 0) {
            return false;
        }
    }

    return true;
}
};