class Solution {
public:
    using P = pair<long long, vector<int>>;

    bool better(const P& a, const P& b) {
        if (a.first != b.first)
            return a.first > b.first;
        return a.second < b.second;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<array<long long, 4>> a(n);

        for (int i = 0; i < n; i++)
            a[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};

        sort(a.begin(), a.end());

        vector<long long> starts(n);
        for (int i = 0; i < n; i++)
            starts[i] = a[i][0];

        vector<int> nxt(n);

        for (int i = 0; i < n; i++)
            nxt[i] = upper_bound(starts.begin(), starts.end(), a[i][1]) - starts.begin();

        vector<vector<P>> dp(n + 1, vector<P>(5, {0, {}}));

        for (int i = n - 1; i >= 0; i--) {
            for (int k = 1; k <= 4; k++) {
                P skip = dp[i + 1][k];

                P take = dp[nxt[i]][k - 1];
                take.first += a[i][2];
                take.second.push_back(a[i][3]);
                sort(take.second.begin(), take.second.end());

                dp[i][k] = better(take, skip) ? take : skip;
            }
        }

        return dp[0][4].second;
    }
};