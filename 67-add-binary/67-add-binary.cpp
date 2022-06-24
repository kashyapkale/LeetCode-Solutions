class Solution {
public:
//BinarySum
pair<char, char> getSingleDigitSum(char A, char B){
	
    if (A == '1' && B == '1')
        return make_pair('1', '0');
    

	if (A == '0' && B == '0')
		return make_pair('0', '0');

	return make_pair('0', '1');
}


void addExtraDigits(string &s, int remainingLength){
	while (remainingLength--)
		s = '0' + s;
}

	
string addBinary(string s1, string s2){
	
	char carry = '0';
	string ans = "";
	int remainingLength = max(s1.length(), s2.length()) - min(s1.length(), s2.length());

	if (s1.length() > s2.length()) {
		addExtraDigits(s2, remainingLength);
	}
	else if (s1.length() < s2.length()) {
		addExtraDigits(s1, remainingLength);
	}

    	int len = max(s1.length(), s2.length());
	while (len) {
		pair<char, char> currSum1 = getSingleDigitSum(s1[len - 1], carry);
		char tempCarry = currSum1.first, tempSum = currSum1.second;
		pair<char, char> currSum2 = getSingleDigitSum(tempSum, s2[len - 1]);
		ans += currSum2.second;
		carry = (currSum2.first == '1') ? '1':tempCarry;
        len--;
	}
	

	if (carry == '1')
		ans += '1';

	reverse(ans.begin(), ans.end());
	return ans;
}

//    abcdef
//defghklmnr





};
