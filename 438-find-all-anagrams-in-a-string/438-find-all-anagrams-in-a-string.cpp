class Solution {
public:
    bool compareHashMap(unordered_map<char, int> &umap, unordered_map<char, int> &umap2){
    for (auto it : umap2) {
        if (umap[it.first] != it.second)
            return false;
    }
    return true;
}
vector<int> findAnagrams(string s, string p) {
    int index = 0;
    int subTextLen = p.length();
    int textLen = s.length();
    vector<int> anagrams;

    if (textLen < subTextLen)
        return anagrams;
    unordered_map<char, int> umap;
    unordered_map<char, int> umap2;

    int k;

    for (k = 0; k < subTextLen; k++) {
        umap[s[k]]++;
        umap2[p[k]]++;
    }

    int j = k;
    if (compareHashMap(umap, umap2)) {
            anagrams.push_back(0);
        }
    
    for (int i = 1; i <= textLen - subTextLen; i++) {
        umap[s[i - 1]]--;
        umap[s[j]]++;
        if (compareHashMap(umap, umap2)) {
            anagrams.push_back(i);
        }
        j++;
    }

    return anagrams;

}
};