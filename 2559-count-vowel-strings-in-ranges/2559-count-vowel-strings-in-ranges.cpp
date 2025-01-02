class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int w = words.size(), q = queries.size();
        vector<int> result(q);

        unordered_set<int> vowels = {'a', 'e', 'i', 'o', 'u'};

        vector<int> prefixSum(w + 1);

        for (int i = 1; i <= w; i++) {
            int wordLen = words[i - 1].length();
            int status = vowels.count(words[i - 1][0]) && vowels.count(words[i - 1][wordLen - 1]) ? 1 : 0;
            prefixSum[i] = prefixSum[i - 1] + status;
        }
        int i = -1;
        for (auto query : queries) {
            result[++i] = prefixSum[query[1] + 1] - prefixSum[query[0]];
        }

        return result;
    }
};