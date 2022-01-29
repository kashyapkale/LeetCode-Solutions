class Solution {
public:
    void findPrevSmaller(vector<int>& heights, vector<int>& prevSmaller){
    stack<int> s;

    s.push(heights.size() - 1);
    for (int i = heights.size() - 2; i >= 0; i--) {
        while (!s.empty() && heights[s.top()] > heights[i]) {
            prevSmaller[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    /*while (!s.empty()) {
        prevSmaller[s.top()] = -1;
        s.pop();
    }*/
}

void findNextSmaller(vector<int>& heights, vector<int>& nextSmaller){
    stack<int> s;

    s.push(0);
    for (int i = 1; i < heights.size(); i++) {
        while (!s.empty() && heights[s.top()] > heights[i]) {
            nextSmaller[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    /*while (!s.empty()) {
        nextSmaller[s.top()] = heights.size();
        s.pop();
    }*/
}

int largestRectangleArea(vector<int>& heights) {
    int N = heights.size();
    vector<int> nextSmaller(N,N);
    vector<int> prevSmaller(N,-1);
    int maxArea = INT_MIN;

    findNextSmaller(heights, nextSmaller);
    findPrevSmaller(heights, prevSmaller);
    for (int i = 0; i < N; i++) {
        int area = (nextSmaller[i] - prevSmaller[i] - 1) * heights[i];
        maxArea = max(maxArea, area);
    }
    return maxArea;
}
};