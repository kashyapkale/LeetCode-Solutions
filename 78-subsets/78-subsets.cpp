class Solution {
public:
    void subsetsHelper(int index, vector<int>&nums, vector<int> &temp, vector<vector<int> > &ans){
    if (index == nums.size()) {
        ans.push_back(temp);
        return;
    }

    temp.push_back(nums[index]);
    subsetsHelper(index + 1, nums, temp, ans);

    temp.pop_back();
    subsetsHelper(index + 1, nums, temp, ans);
}

vector<vector<int> > subsets(vector<int>& nums) {
    vector<vector<int> > ans;
    vector<int> temp;

    subsetsHelper(0, nums, temp, ans);
    return ans;
}
};