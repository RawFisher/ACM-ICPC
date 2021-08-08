#include <bits/stdc++.h>
using namespace std;


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> a;
    vector<int> b;
    a.resize(n+1);
    b.resize(n+1);
    for (int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        a[u]++; a[v]++;
        if (u > v) b[u]++;
        else b[v]++;
    }
    int res = 0;
    for (int i=1; i<=n; i++) {
        if (a[i] == b[i]) res++;
    }
    int q;
    cin >> q;
    for (int i=0; i<q; i++) {
        int o;
        cin >> o;
        if (o == 3) {
            cout << res << endl;
        } else if (o == 1) {
            int u, v;
            cin >> u >> v;
            a[u]++; a[v]++;
            if (u > v) b[u]++;
            else b[v]++;
            if (a[max(u,v)]!=b[max(u,v)]) res--;
        } else {
            int u, v;
            cin >> u >> v;
            a[u]--; a[v]--;
            if (u > v) b[u]--;
            else b[v]--;
            if (a[max(u,v)]==b[max(u,v)]) res++;
        }
    }
    return 0;
}
