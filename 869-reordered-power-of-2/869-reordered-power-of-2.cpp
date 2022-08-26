class Solution {
public:
    bool reorderedPowerOf2(int n) {
    vector<unsigned int> digitMask(10, 0);
    unsigned int k = n;
    
    int originalCountOfDigits = 0;    
    while (k) {
        digitMask[k % 10]++;
        k = k / 10;
        originalCountOfDigits++;
    }
    
    int limit = pow(10,9);
    for (unsigned int i = 1; i <= limit; i = i * 2) {
        unsigned int temp = i;
        vector<unsigned int> tempDigitMask(10, 0);
        int tempCountOfDigits = 0;
        while (temp) {
            tempCountOfDigits++;
            tempDigitMask[temp % 10]++;
            temp = temp / 10;
        }
        
        if(tempCountOfDigits>originalCountOfDigits)
            return false;

        bool flag = true;
        for (unsigned int m = 0; m < 10; m++) {
            if (tempDigitMask[m] != digitMask[m])
                flag = false;
        }

        if (flag)
            return true;
    }

    return false;
}
};