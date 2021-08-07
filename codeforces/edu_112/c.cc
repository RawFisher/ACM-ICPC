#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int m;
        cin >> m;
        vector<vector<int>> a(2);
        int sum = 0;
        for (int i=0; i<2; i++) {
            a[i].resize(m);
            for (int j=0; j<m; j++) {
                cin >> a[i][j];
                if (i == 0) sum += a[i][j];
            }
        }
        int suf_0 = sum;
        int pre_1 = 0;
        int res = (int)1e9;
        for (int i=0; i<m; i++) {
            suf_0 = suf_0 - a[0][i];
            if (i > 0) pre_1 = pre_1 + a[1][i-1];
            res = min(res, max(suf_0, pre_1));
        }
        cout << res << endl;
    }
    return 0;
}
