class Solution {
public:
    int mod = 1e9 + 7;
    
    int solve(int i, vector<vector<int>>& nextPos, vector<int>& dp) {
        if (dp[i] != -1) return dp[i];
        
        int count = 1;
        
        for (int c = 0; c < 26; c++) {
            if (nextPos[c][i] != -1) {
                count = (count + solve(nextPos[c][i], nextPos, dp)) % mod;
            }
        }
        
        return dp[i] = count;
    }

    int distinctSubseqII(string s) {
        int n = s.length();
        
        vector<vector<int>> nextPos(26, vector<int>(n, -1));
        vector<int> dp(n, -1);
        vector<int> last(26, -1); 
        
        for (int i = n - 1; i >= 0; i--) {
            for (int c = 0; c < 26; c++) {
                nextPos[c][i] = last[c];
            }
            last[s[i] - 'a'] = i; 
        }
        
        int ans = 0;
        

        for (int c = 0; c < 26; c++) {
            if (last[c] != -1) {
                ans = (ans + solve(last[c], nextPos, dp)) % mod;
            }
        }

        return ans;
    }
};