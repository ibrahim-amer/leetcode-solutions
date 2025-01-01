class Solution {
public:
    int maxScore(string s) {
        int leftScore = 0, rightScore = 0, n = s.length();

        for (int i = 0; i < n; i++) rightScore = s[i] == '1' ? (rightScore + 1) : rightScore;

        int maxScore = INT_MIN;

        for (int i = 0; i < n - 1; i++) {
            leftScore = s[i] == '0' ? (leftScore + 1) : leftScore;
            rightScore = s[i] == '1' ? (rightScore - 1) : rightScore;
            maxScore = max(maxScore, leftScore + rightScore);
        }

        return maxScore;
    }
};