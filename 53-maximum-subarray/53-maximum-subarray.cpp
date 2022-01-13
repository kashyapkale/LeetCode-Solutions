class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maximum = INT_MIN;
        int sum = 0;
        for(auto it : nums){
            sum+=it;
            maximum = max(maximum,sum);
            if(sum<0)
                sum = 0;
        }
        
        return maximum;
    }
};