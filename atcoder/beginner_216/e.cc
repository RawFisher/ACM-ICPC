#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    while (cin >> n >> k) {
        vector<int> a(n+1, 0);
        for (int i=0; i<n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());
        // for (auto& x: a) cout << x << " ";
        // cout << endl;
        LL res = 0;
        int tot_step = 0;
        for (int i=0; i<n; ) {
            int j = i;
            while (j<n && a[i]==a[j]) j++;
            LL lap = a[i] - a[j];
            LL step = j * lap;
            // cout << "i=" << i << " j=" << j << endl;
            // cout << "res=" << res << endl;
            // cout << "lap=" << lap << endl;
            // cout << "step=" << step << endl;
            if (tot_step + step >= k) {
                int left = k - tot_step;
                int x = left / j;
                int y = left % j;
                // cout << "left=" << left << endl;
                // cout << "x="<<x <<"y="<<y<< endl;
                res += 1LL * (1LL*a[i]+a[i]-x+1) * x / 2 * j;
                res += 1LL * y * (a[i]-x);
                break;
            } else {
                res += 1LL * (1LL*a[i]+a[j]+1) * lap / 2 * j;
                tot_step += step;
            }
            i = j;
        }
        cout << res << endl;
    }
    return 0;
}
