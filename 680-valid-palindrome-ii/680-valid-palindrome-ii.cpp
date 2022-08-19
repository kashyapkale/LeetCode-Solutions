class Solution {
public:
    bool isPalindrome(string s){
    int high = s.length() - 1;
    int low = 0;

    while (low <= high) {
        if (s[low] != s[high])
            return false;

        low++;
        high--;
    }

    return true;
}


bool validPalindrome(string s) {
    int high = s.length() - 1;
    int low = 0;

    while (low <= high) {
        if (s[low] != s[high]) {
            return isPalindrome(s.substr(low, high - low))
                   || isPalindrome(s.substr(low + 1, high - low));
        }
        low++;
        high--;
    }

    return true;
}
};