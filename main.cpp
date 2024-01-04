#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size() + 1, n = p.size() + 1;
        vector<vector<bool>> dp(m, vector<bool>(n, false));
        dp[0][0] = true;
        // 初始化首行
        for(int j = 2; j < n; j += 2)
            dp[0][j] = dp[0][j - 2] && p[j - 1] == '*';
        // 状态转移
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if (p[j - 1] == '*') {
                    if (dp[i][j - 2]) dp[i][j] = true;                              // 1.
                    else if (dp[i - 1][j] && s[i - 1] == p[j - 2]) dp[i][j] = true; // 2.
                    else if (dp[i - 1][j] && p[j - 2] == '.') dp[i][j] = true;      // 3.
                } else {
                    if (dp[i - 1][j - 1] && s[i - 1] == p[j - 1]) dp[i][j] = true;  // 1.
                    else if (dp[i - 1][j - 1] && p[j - 1] == '.') dp[i][j] = true;  // 2.
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main() {
    Solution sol;

    for (int i = 0; i < 3; ++i) {
        string s, p;

        cout << "Enter input string #" << i + 1 << ": ";
        cin >> s;

        cout << "Enter pattern #" << i + 1 << ": ";
        cin >> p;

        bool result = sol.isMatch(s, p);
        cout << "Is there a match? " << (result ? "Yes" : "No") << endl;
    }

    return 0;
}
