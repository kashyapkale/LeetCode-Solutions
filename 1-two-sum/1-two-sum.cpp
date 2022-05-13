class Solution {
public:
vector<int> twoSum(vector<int>& nums, int target) {
   int left = 0;
   int right = nums.size() - 1;
   vector<int> ans;
   unordered_map<int, vector<int> > umap;

   for (int i = 0; i <= right; i++) {
      umap[nums[i]].push_back(i);
   }


   sort(nums.begin(), nums.end());
   while (right > left) {
      int curr_sum = nums[right] + nums[left];
      if (curr_sum == target) {
         if (nums[right] == nums[left]) {
            ans.push_back(umap[nums[right]][0]);
            ans.push_back(umap[nums[left]][1]);
         }
         else{
            ans.push_back(umap[nums[right]][0]);
            ans.push_back(umap[nums[left]][0]);
         }
         return ans;
      }

      if (target > curr_sum)
         left++;
      else
         right--;
   }


   return ans;
}
};