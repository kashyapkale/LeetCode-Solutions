class Solution {
public:
    static bool comparator(vector<int> &A, vector<int>&B){
        if(A[0]!=B[0])
            return A[0] < B[0];
        else
            return A[1] > B[1];
}           


int removeCoveredIntervals(vector<vector<int> >& intervals) {
    sort(intervals.begin(), intervals.end(), comparator);
    int j = 1, i = 0;
    int cnt = 0;

    while (j < intervals.size()) {
        if (intervals[i][1] >= intervals[j][1]) {
            cnt++;
            j++;
        }
        else{
            i = j;
            j++;
        }
    }
    return intervals.size()-cnt;
}
};