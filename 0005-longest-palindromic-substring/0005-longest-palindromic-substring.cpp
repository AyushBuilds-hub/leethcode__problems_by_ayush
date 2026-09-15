class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";

        int start = 0, end = 0;

        auto expand = [&](int left, int right) -> int {
            while (left >= 0 && right < (int)s.size() && s[left] == s[right]) {
                left--;
                right++;
            }
            return right - left - 1; // length of palindrome
        };

        for (int i = 0; i < (int)s.size(); i++) {
            int len1 = expand(i, i);       // odd length
            int len2 = expand(i, i + 1);   // even length
            int maxLen = max(len1, len2);

            if (maxLen > end - start + 1) {
                start = i - (maxLen - 1) / 2;
                end = i + maxLen / 2;
            }
        }

        return s.substr(start, end - start + 1);
    }
};