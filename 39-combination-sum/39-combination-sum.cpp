class Solution {
public:
    void combinationSumUtil(int index, vector<int>& candidates, int target, vector<vector<int> > &ans, vector<int> &temp){
    if (target == 0) {
        ans.push_back(temp);
        return;
    }


    if (target < 0 || index >= candidates.size()) {
        return;
    }

    if (candidates[index] <= target) {
        temp.push_back(candidates[index]);
        combinationSumUtil(index, candidates, target - candidates[index], ans, temp);
        temp.pop_back();
    }


    combinationSumUtil(index + 1, candidates, target, ans, temp);
}


vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
    vector<int> temp;
    vector<vector<int> > ans;

    combinationSumUtil(0, candidates, target, ans, temp);
    return ans;
}
};