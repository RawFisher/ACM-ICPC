#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const LL P = 998244353;
const int N = 5000 + 5;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin >> n) {
        vector<int> a(n+1), b(n+1);
        for (int i=1; i<=n; i++) {
            cin >> a[i];
        }
        for (int i=1; i<=n; i++) {
            cin >> b[i];
        }
        vector<pair<int, int>> c;
        c.push_back(make_pair(0, 0));
        for (int i=1; i<=n; i++) {
            c.push_back(make_pair(a[i], b[i]));
        }
        sort(c.begin(), c.end());
        // for (auto& x: c) cout << x.first << " " << x.second << endl;

        LL res = 0;
        vector<vector<LL>> dp(n+1, vector<LL>(N, 0));
        dp[0][0] = 1;
        for (int i=1; i<=n; i++) {
            auto x = c[i];
            // cout << x.first << " " << x.second << endl;
            for (int j=x.second; j<N; j++) {
                dp[i][j] = (dp[i][j] + dp[i-1][j-x.second]) % P;
            }
            for (int j=0; j<=x.first; j++) {
                res = (res + dp[i][j]) % P;
            }
            for (int j=0; j<N; j++) {
                dp[i][j] = (dp[i][j] + dp[i-1][j]) % P;
                // cout << "j=" << j << " " << dp[i][j] << " ";
            }
            // cout << endl;
        }
        cout << res << endl;
    }
    return 0;
}
