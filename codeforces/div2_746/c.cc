#include <bits/stdc++.h>
using namespace std;

int dfs(int root, vector<bool>& vis, vector<vector<int>>& edge, vector<int>& a, int target, int& cnt)
{
    vis[root] = true;
    int res = a[root];

    for (auto& v: edge[root]) {
        if (vis[v]) continue;
        res ^= dfs(v, vis, edge, a, target, cnt);
    }
    if (res == target) {
        cnt++;
        return 0;
    }
    else {
        return res;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n+1);
        for (int i=1; i<=n; i++) {
            cin >> a[i];
        }
        vector<vector<int>> e(n+1, vector<int>());
        for (int i=0; i<n-1; i++) {
            int u, v;
            cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        int tot = 0;
        for (auto& x: a) {
            tot ^= x;
        }

        if (tot == 0) {
            cout << "YES\n";
        }
        else {
            if (k == 2) {
                cout << "NO\n";
                continue;
            }
            vector<bool> vis(n+1, false);
            int cnt = 0;
            dfs(1, vis, e, a, tot, cnt);
            if (cnt>=2) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}
