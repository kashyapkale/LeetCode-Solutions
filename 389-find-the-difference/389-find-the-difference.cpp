class Solution {
public:
    char findTheDifference(string s, string t) {
    int dp[26] = { 0 };

    for (auto ch:s) {
        dp[ch - 'a']++;
    }

    for (auto ch:t) {
        if (dp[ch - 'a'] == 0)
            return ch;
        else
            dp[ch - 'a']--;
    }

    return '-1';
}
};