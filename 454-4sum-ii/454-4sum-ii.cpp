class Solution {
public:
   int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
   unordered_map<int, int> umap1;
   unordered_map<int, int> umap2;


   int N = nums1.size();

   for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
         int tempSum = nums1[i] + nums2[j];
         if (umap1.find(tempSum) != umap1.end())
            umap1[tempSum]++;
         else
            umap1[tempSum] = 1;
      }
   }

   for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
         int tempSum = nums3[i] + nums4[j];
         if (umap2.find(tempSum) != umap2.end())
            umap2[tempSum]++;
         else
            umap2[tempSum] = 1;
      }
   }

   int ans = 0;

   for (auto it:umap1) {
      if (umap2.find(it.first * -1) != umap2.end()) {
         ans += (it.second * umap2[it.first * -1]);
      }
   }

   return ans;
}
};