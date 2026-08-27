class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int left = 0;
        int ones = 0;
        int minLen = INT_MAX;
        string ans = "";

        for (int right = 0; right < n; right++) {
            if (s[right] == '1')
                ones++;

            while (ones == k) {
                int len = right - left + 1;

                if (len < minLen) {
                    minLen = len;
                    ans = s.substr(left, len);
                }
                else if (len == minLen) {
                    string curr = s.substr(left, len);
                    if (curr < ans)
                        ans = curr;
                }

                if (s[left] == '1')
                    ones--;

                left++;
            }
        }

        return ans;
    }
};