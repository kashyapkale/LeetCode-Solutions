class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = 0,j = 0;
    vector<int> tempAns;
    while(i<m && j<n){
        if(nums1[i] < nums2[j]){
            tempAns.push_back(nums1[i]);
            i++;
        }else{
            tempAns.push_back(nums2[j]);
            j++;
        }
    }

    while(i<m){
        tempAns.push_back(nums1[i]);
        i++;
    }

    while(j<n){
        tempAns.push_back(nums2[j]);
        j++;
    }

    i=0;
    for(auto it:tempAns){
        nums1[i] = it;
        i++;
    }
}

};