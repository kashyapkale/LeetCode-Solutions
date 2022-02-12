class Solution {
public:
        int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> wordDict;
    bool isPresent = false;

    for (auto it:wordList) {
        if (endWord.compare(it) == 0) {
            isPresent = true;
        }
        wordDict.insert(it);
    }

    if (!isPresent)
        return 0;

    queue<string> wordQueue;

    wordQueue.push(beginWord);
    int ans = 0;

    while (!wordQueue.empty()) {
        ans += 1;
        int qSize = wordQueue.size();
        while(qSize--){
            string currWord = wordQueue.front();
        wordQueue.pop();
        for (int i = 0; i < currWord.length(); i++) {
            string temp = currWord;
            for (char ch = 'a'; ch <= 'z'; ch++) {
                temp[i] = ch;
                if (currWord.compare(temp)==0)
                    continue;
                if (temp.compare(endWord) == 0)
                    return ans + 1;
                if (wordDict.find(temp) != wordDict.end()) {
                    wordQueue.push(temp);
                    wordDict.erase(temp);
                }
            }
        }
        }
    }

    return 0;
}
};