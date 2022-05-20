class Solution {
public:
    string getKeyMapping(char digit){
    string keyMapping;

    switch (digit) {
    case '2':
        keyMapping = "abc";
        break;
    case '3':
        keyMapping = "def";
        break;
    case '4':
        keyMapping = "ghi";
        break;
    case '5':
        keyMapping = "jkl";
        break;
    case '6':
        keyMapping = "mno";
        break;
    case '7':
        keyMapping = "pqrs";
        break;
    case '8':
        keyMapping = "tuv";
        break;
    case '9':
        keyMapping = "wxyz";
        break;
    default:
        keyMapping = "-1";
        break;
    }

    return keyMapping;

}

vector<string> letterCombinations(string digits) {

    if (digits.length() == 0) {
        vector<string> ans;
        //ans.push_back("");
        return ans;
    }
    
    
    string tempNum;
    if(digits.length() == 1){
        tempNum = "";
    }
    else{
        tempNum = digits.substr(1, digits.length() - 1);
    }
    
    vector<string> temp = letterCombinations(tempNum);
    
    if(temp.size() == 0)
        temp.push_back("");
    
    vector<string> ans;
    string keyMapping = getKeyMapping(digits[0]);

    for (int i = 0; i < keyMapping.size(); i++) {
        for (auto it2 : temp) {
            ans.push_back(keyMapping[i] + it2);
        }
    }

    return ans;

}
};