class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> arr;

        for (int i = 0; i < m - 1; i++) {
            arr.push_back("." + string(n - 1, '#'));
        }

        arr.push_back(string(n, '.'));

        return arr;
    }
};