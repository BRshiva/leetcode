class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        vector<int> cntS(26, 0);
        vector<int> cntT(26, 0);

        for (char c : s)
            cntS[c - 'a']++;

        for (char c : target)
            cntT[c - 'a']++;

        // Difference between characters in s and target
        vector<int> diff(26);

        for (int i = 0; i < 26; i++)
            diff[i] = cntS[i] - cntT[i];

        // Try to change the rightmost possible position
        for (int i = n - 1; i >= 0; i--) {

            // Put target[i] back because position i will be changed
            diff[target[i] - 'a']++;

            // Check if all remaining characters can be used
            bool possible = true;

            for (int c = 0; c < 26; c++) {
                if (diff[c] < 0) {
                    possible = false;
                    break;
                }
            }

            if (!possible)
                continue;

            // Find smallest character greater than target[i]
            for (int c = target[i] - 'a' + 1; c < 26; c++) {
                if (diff[c] > 0) {
                    string ans = target.substr(0, i);

                    ans += char('a' + c);

                    diff[c]--;

                    // Add remaining characters in sorted order
                    for (int x = 0; x < 26; x++) {
                        ans += string(diff[x], char('a' + x));
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};