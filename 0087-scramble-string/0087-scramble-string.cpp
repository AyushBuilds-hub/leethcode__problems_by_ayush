class Solution {
public:
    string s1, s2;
    int n;
    
    // dp[i][j][len] = -1 unknown, 0 false, 1 true
    int dp[30][30][31];

    bool solve(int i, int j, int len) {
        if (dp[i][j][len] != -1)
            return dp[i][j][len];

        // Same substring
        bool same = true;
        for (int k = 0; k < len; k++) {
            if (s1[i + k] != s2[j + k]) {
                same = false;
                break;
            }
        }

        if (same)
            return dp[i][j][len] = 1;

        // Check whether both substrings have the same characters.
        int freq[26] = {};

        for (int k = 0; k < len; k++) {
            freq[s1[i + k] - 'a']++;
            freq[s2[j + k] - 'a']--;
        }

        for (int x : freq) {
            if (x != 0)
                return dp[i][j][len] = 0;
        }

        // Try every possible split.
        for (int k = 1; k < len; k++) {

            // Case 1: Don't swap
            if (solve(i, j, k) &&
                solve(i + k, j + k, len - k)) {
                return dp[i][j][len] = 1;
            }

            // Case 2: Swap
            if (solve(i, j + len - k, k) &&
                solve(i + k, j, len - k)) {
                return dp[i][j][len] = 1;
            }
        }

        return dp[i][j][len] = 0;
    }

    bool isScramble(string s1, string s2) {
        if (s1.length() != s2.length())
            return false;

        this->s1 = s1;
        this->s2 = s2;
        n = s1.length();

        memset(dp, -1, sizeof(dp));

        return solve(0, 0, n);
    }
};
