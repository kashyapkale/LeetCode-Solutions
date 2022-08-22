class Solution {
public:
bool isPowerOfFour(int n) {

    if (n == 1)
        return true;
    else if (n > 1 && n < 4)
        return false;
    else if(n <= 0)
        return false;
    else{
        return (n%4 == 0) && isPowerOfFour(n/4);
    }

    return false;

}
};