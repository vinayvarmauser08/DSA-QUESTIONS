class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int i = 0;
        int count = 0;
        int len = INT_MAX;
        string ans = s;

        for (int j = 0; j < n; j++) {

            if (s[j] == '1')
                count++;

            while (i < n && (count > k || s[i] == '0')) {
                if (s[i] == '1')
                    count--;
                i++;
            }

            if (count == k) {
                int currLen = j - i + 1;
                string curr = s.substr(i, currLen);

                if (currLen < len) {
                    len = currLen;
                    ans = curr;
                }
                else if (currLen == len && curr < ans) {
                    ans = curr;
                }
            }
        }

        return len == INT_MAX ? "" : ans;
    }
};