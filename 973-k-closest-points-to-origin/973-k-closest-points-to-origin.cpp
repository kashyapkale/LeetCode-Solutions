class Solution {
public:
    int calculateDistance(int x, int y){
    return (x * x) + (y * y);
}


vector<vector<int> > kClosest(vector<vector<int> >& points, int k) {
    //vector<pair<int, int> > distance;
    priority_queue<pair<int, int>> maxHeap;
    int index = 0;

    for (auto point:points) {
        maxHeap.push(make_pair(calculateDistance(point[0], point[1]), index));
        index++;

        if(maxHeap.size()>k){
            maxHeap.pop();
        }
    }
    //sort(distance.begin(), distance.end());
    vector<vector<int> > ans;

    while(!maxHeap.empty()){
        ans.push_back(points[maxHeap.top().second]);
        maxHeap.pop();
    }

    return ans;
}
};