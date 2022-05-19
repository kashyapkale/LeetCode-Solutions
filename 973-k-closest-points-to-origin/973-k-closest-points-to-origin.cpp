class Solution {
public:
    int calculateDistance(int x, int y){
    return (x * x) + (y * y);
}

vector<vector<int> > kClosest(vector<vector<int> >& points, int k) {
    vector<pair<int, int> > distance;
    int index = 0;

    for (auto point:points) {
        distance.push_back(make_pair(calculateDistance(point[0], point[1]), index));
        index++;
    }
    sort(distance.begin(), distance.end());
    vector<vector<int> > ans;

    index = 0;
    while (index < k) {
        ans.push_back(points[distance[index].second]);
        index++;
    }

    return ans;
}
};