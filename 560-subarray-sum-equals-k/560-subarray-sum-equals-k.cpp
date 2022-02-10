class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> umap;
    int ans = 0;

    umap[0] = 1;
    int prefixSum = 0;

    for (int i = 0; i < nums.size(); i++) {
        prefixSum += nums[i];
        if (umap.find(prefixSum - k) != umap.end())
            ans+=umap[prefixSum-k];
        umap[prefixSum]++;
    }
    return ans;
}
};