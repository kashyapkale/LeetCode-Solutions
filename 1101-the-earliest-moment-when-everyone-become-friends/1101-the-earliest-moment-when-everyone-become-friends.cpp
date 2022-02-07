class DSU {
    vector<int> par, cap;
public:
    DSU(int n) {
        par.resize(n);
        cap.resize(n);
        for(int i = 0; i < n; i++) {
            par[i] = i;
            cap[i] = 1;
        }
    }
    
    int findParent(int a) {
        while(par[a] != a) {
            par[a] = par[par[a]];
            a = par[a];
        }
        return a;
    }
    
    bool find(int a, int b){
        return findParent(a) == findParent(b);
    }
    
    void unionPar(int a, int b) {
        if(find(a, b)) return;
        int rootA = findParent(a);
        int rootB = findParent(b);
        if(cap[rootA] < cap[rootB]) {
            par[rootA] = par[rootB];
            cap[rootB] += cap[rootA];
        }   
        else {
            par[rootB] = par[rootA];
            cap[rootA] += cap[rootB];
        }
    }
    bool allMerged(int a, int b) {
        return cap[findParent(a)] == cap.size() || cap[findParent(b)] == cap.size();
    }
};

class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        sort(logs.begin(), logs.end());
        DSU* dsu = new DSU(n);
        for(auto log: logs) {
            int currTime = log[0];
            int friend1 = log[1];
            int friend2 = log[2];
            dsu->unionPar(friend1, friend2);
            if(dsu->allMerged(friend1, friend2)) {
                return currTime;
            }
        }
        return -1;
    }
};