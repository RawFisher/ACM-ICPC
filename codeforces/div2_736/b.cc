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
        int n, m;
        cin >> n >> m;
        vector<unorder_set<int>> a;
        a.resize(n+1);
        for (int i=0; i<m; i++) {
            int u, v;
            cin >> u >> v;
            a[u].insert(v);
            a[v].insert(u);
        }
        cin >> q;
        vector<unordered_set<int>> b = a;
        for (int i=0; i<q; i++) {
            int o;
            cin >> o;
            if (o == 3) {
                for (int j=1; j<=n; j++) {
                    if (b[j].size() != 0) {
                        for (auto x: b[j]) b[x].erase(j);
                        res++;
                    }
                }
            } else if (o == 1) {
                int u, v;
                cin >> u >> v;
                b[u].insert(v);
                b[v].insert(u);
            } else {
                int u, v;
                cin >> u >> v;
                b[u].erase(v);
                b[v].erase(u);
            }
        }
    }
    return 0;
}
