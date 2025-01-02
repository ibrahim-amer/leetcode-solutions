class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        const unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        vector<int> prefix(words.size());
        vector<int> ans(queries.size());
        int curr = 0, i = 0;
        for(auto& word: words) {
            curr += vowels.count(word[0]) && vowels.count(word[word.length()-1]) ? 1 : 0;
            prefix[i++] = curr;
        }
        i = 0;
        for(auto& query: queries) {
            if(query[0] > 0) ans[i++] = prefix[query[1]] - prefix[query[0]-1];
            else ans[i++] = prefix[query[1]];
        }
        return ans;
    }
};