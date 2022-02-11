class Solution {
public:
    bool checkInclusion(string s1, string s2) {
    unordered_map<char, int>umap1;
    unordered_map<char, int>umap2;
    if(s1.length()>s2.length())
        return false;
        
    for (auto it:s1) {
        umap1[it]++;
    }

    int i = 0;
    int j = i + s1.length() - 1;
    int k = 0;

    while (k <= j) {
        umap2[s2[k]]++;
        k++;
    }

    if (umap1 == umap2)
        return true;

    int N = s2.length();

    while (j < N) {
        umap2[s2[i]]--;
        if (umap2[s2[i]] == 0) {
            umap2.erase(s2[i]);
        }
        i++;
        j++;

        if (j < N) {
            umap2[s2[j]]++;
            if (umap1 == umap2)
                return true;
        }
    }
    return false;
}
};