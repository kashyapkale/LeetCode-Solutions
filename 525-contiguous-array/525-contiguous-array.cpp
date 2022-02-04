class Solution {
public:
    int findMaxLength(vector<int>& nums) {
    unordered_map<int, int> umap;

    umap[0] = -1;
    int ans = INT_MIN;
    int prefix = 0;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0)
            prefix += -1;
        else
            prefix += 1;

        if (umap.find(prefix) != umap.end()) {
            ans = max(ans, i - umap[prefix]);
        }
        else{
            umap[prefix] = i;
        }
    }
    return (ans==INT_MIN)?0:ans;
}
};