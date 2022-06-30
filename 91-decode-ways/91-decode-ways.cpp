class Solution {
public:
int numDecodingsUtil(string s, int len, vector<int> &dp) {

    if (dp[len] != -1)
        return dp[len];

    if (s[0] == '0')
        return dp[len] = 0;

    if (len == 0)
        return dp[len] = 0;

    if (len == 1)
        return dp[len] = 1;

    if (len == 2) {
        if (s[0] != '0' && s[1] != '0')
            return dp[len] = (stoi(s.substr(0, 2)) <= 26) ? 2 : 1;
        else if ((s[0] == '1' || s[0] == '2') && s[1] == '0')
            return dp[len] = 1;
        else
            return dp[len] = 0;
    }


    int singleDigit = (dp[len-2] == -1)?numDecodingsUtil(s.substr(1, len - 1), len - 1,dp) : dp[len-2];
    int doubleDigit = 0;

    if (s.length() >= 2 && (stoi(s.substr(0, 2)) <= 26)) {
        doubleDigit = (dp[len-2] == -1)?numDecodingsUtil(s.substr(2, len - 2), len - 2,dp) : dp[len-2];
    }

    return dp[len] = singleDigit + doubleDigit;

}
int numDecodings(string s){
    vector<int> dp(s.length() + 1, -1);

    return numDecodingsUtil(s, s.length(), dp);
}

};