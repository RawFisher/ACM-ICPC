#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL P = 998244353;
LL dp[1010][1030][15];

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string s;
    while (cin >> n >> s) {
        memset(dp, 0, sizeof(dp));
        for (int i=1; i<=n; i++) {
            int c = s[i-1] - 'A';
            // cout << "yes\n";
            // cout << c << endl;
            dp[i][(1<<c)][c] = (dp[i][(1<<c)][c] + 1) % P;
            // cout << "yes\n";
            for (int S=0; S<1024; S++) {
                for (int j=0; j<10; j++) {
                    dp[i][S][j] = (dp[i][S][j] + dp[i-1][S][j]) % P;  // not participant
                    if (j == c) {
                        dp[i][S][j] = (dp[i][S][j] + dp[i-1][S][j]) % P;
                    }
                    // participant
                    if ((S & (1<<c))!=0) {
                        int T = (S ^ (1 << c));
                        dp[i][S][c] = (dp[i][S][c]+dp[i-1][T][j]) % P;
                    }
                }
            }
        }
        LL res = 0;
        for (int S=0; S<1024; S++) {
            for (int j=0; j<10; j++) {
                res = (res + dp[n][S][j]) % P;
            }
        }
        cout << res << endl;
    }

    return 0;
}
