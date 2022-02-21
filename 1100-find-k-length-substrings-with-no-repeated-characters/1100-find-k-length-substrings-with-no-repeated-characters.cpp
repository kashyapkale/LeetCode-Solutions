class Solution {
public:
    bool isAWord(unordered_map<char, int> &umap){
    for (auto it : umap) {
        if (it.second > 1) {
            return false;
        }
    }

    return true;
}

int numKLenSubstrNoRepeats(string s, int k) {
    int i = 0;
    int j = i + k - 1;
    int ans = 0;
    unordered_map<char, int> umap;
    if(s.length()<k)
        return ans;
    for (int k = i; k <= j; k++) {
        umap[s[k]]++;
    }
    if (isAWord(umap))
        ans++;

    while (j < s.length()-1) {
        
        umap[s[i]]--;
        if (umap[s[i]] == 0)
            umap.erase(umap[s[i]]);
        umap[s[++j]]++;
        i++;

        if (isAWord(umap))
            ans++;
    }
    return ans;

}
};