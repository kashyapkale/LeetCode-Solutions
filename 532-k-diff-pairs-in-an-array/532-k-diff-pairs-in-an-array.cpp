class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
    unordered_map<int, int> umap;

    for (auto it:nums) {
        umap[it]++;
    }

    int ans = 0;

    if (k == 0) {
        for (auto it:umap) {
            if (it.second >= 2) {
                ans++;
            }
        }
    }
    else{
        for (auto it:umap) {
            if (umap.find(it.first + k) != umap.end()) {
                ans++;
            }
        }
    }
    return ans;
}
};