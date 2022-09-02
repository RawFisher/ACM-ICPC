#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    int n; cin >> n;
    ll p, q, r; cin >> p >> q >> r;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    vector<ll> pre(n+1, 0);
    for (int i=1; i<=n; i++) pre[i] = pre[i-1]+a[i-1];
    for (int i=0; i<n; i++) {
        auto x = pre.begin() + i;
        auto y = lower_bound(pre.begin()+i, pre.end(), *x+p);
        if (y==pre.end() || *y!=*x+p) {
            continue;
        }
        auto z = lower_bound(y, pre.end(), *y+q);
        if (z==pre.end() || *z!=*y+q) {
            continue;
        }
        auto w = lower_bound(z, pre.end(), *z+r);
        if (w==pre.end() || *w!=*z+r) {
            continue;
        }
        // printf("%d %d %d %d\n", x-pre.begin(), y-pre.begin(), z-pre.begin(), w-pre.begin());
        cout << "Yes\n";
        return 0;
    }
    cout << "No\n";
    return 0;
}
