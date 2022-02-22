class Solution {
public:
    int fixedPoint(vector<int>& arr) {
        int i = 0;
        for(auto it:arr){
            if(it == i)
                return i;
            i++;
        }
        return -1;
    }
};