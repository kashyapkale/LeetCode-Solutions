class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    //1-Check which is smaller Array
    if (nums1.size() > nums2.size())
        swap(nums1, nums2);

    int len1 = nums1.size();
    int len2 = nums2.size();

    //2-Binary Search on Smaller Array
    int high = len1;
    int low = 0;

    while (low <= high) {
        //3-Find Cut 1 and Cut 2
        int cut1 = (low + high) / 2;
        int cut2 = ((len1 + len2) / 2) - cut1;

        //4-Find Left1,Left2,Right1,Right2
        int left1 = (cut1 == 0)?INT_MIN:nums1[cut1 - 1];
        int left2 = (cut2 == 0)?INT_MIN:nums2[cut2 - 1];
        int right1 = (cut1 == len1)?INT_MAX:nums1[cut1];
        int right2 = (cut2 == len2)?INT_MAX:nums2[cut2];

        //5-Reduce Search Scope
        if (left1 > right2) {
            high = cut1 - 1;
        }
        else if (left2 > right1) {
            low = cut1 + 1;
        }
        else{
            //6-Return Median
            return ((len1 + len2) % 2 == 0) ?
                   double((max(left1, left2) + min(right1, right2)) / 2.0):
                   min(right1,right2);
        }
    }


    return -1;
}
};