class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        int onesCount = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                onesCount++;
            }
        }

        int maxScore = INT_MIN;
        int zerosCount = 0;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '0') {
                zerosCount++;
            } else if (s[i] == '1') {
                onesCount--;
            }
            if (zerosCount + onesCount >= maxScore) {
                maxScore = zerosCount + onesCount;
            }
        }
        return maxScore;
    }
};

