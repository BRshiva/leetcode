class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> mp;
        for(auto &seat : reservedSeats){
            int row = seat[0];
            int col = seat[1];
            
                mp[row] |= (1 << col);
            
        }
        int ans = (n - mp.size()) * 2;
        for (auto &[row, mask] : mp){
            bool Left = (mask & 60) == 0;
            bool Middle = (mask & 240) == 0;
            bool Right = (mask & 960) == 0;
            if(Left && Right){
                ans += 2;
            }
            else if (Left || Middle || Right){
                ans += 1;
            }
        }
        return ans;
    }
};