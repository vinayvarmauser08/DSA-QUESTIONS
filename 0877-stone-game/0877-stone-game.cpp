class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        /**
        return true;
        */
        int n = piles.size();
        vector<int> dp(n, 0);

        for (int left = n - 1; left >= 0; left--) {
            for (int right = left; right < n; right++) {
                int turn = (left + right) % 2;

                if (left == right) {
                    dp[right] = 0;
                } else {
                    if (turn) {
                        dp[right] = max(
                            piles[left] + dp[right],
                            piles[right] + dp[right - 1]
                        );
                    } else {
                        dp[right] = min(
                            dp[right],
                            dp[right - 1]
                        );
                    }
                }
            }
        }

        int total = accumulate(piles.begin(), piles.end(), 0);

        return dp[n - 1] > total - dp[n - 1];
    }
};