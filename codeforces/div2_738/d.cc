#include <bits/stdc++.h>
using namespace std;


int Find(int node, vector<int> &f)
{
    while (f[node] != node) {
        f[node] = f[f[node]];
        node = f[node];
    }
    return node;
}


void Union(int u, int v, vector<int> &f)
{
    int uroot = Find(u, f);
    int vroot = Find(v, f);

    if (uroot != vroot) {
        f[uroot] = vroot;
    }
}


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> f1(n+1), f2(n+1);
    for (int i=1; i<=n; i++) {
        f1[i]=i;
        f2[i]=i;
    }
    int m1, m2;
    cin >> m1 >> m2;
    for (int i=0; i<m1; i++) {
        int u, v;
        cin >> u >> v;
        Union(u, v, f1);
    }
    for (int i=0; i<m2; i++) {
        int u, v;
        cin >> u >> v;
        Union(u, v, f2);
    }
    vector<pair<int, int>> res;
    for (int u=1; u<=n; u++) {
        for (int v=u+1; v<=n; v++) {
            if (Find(u, f1)!=Find(v, f1) && Find(u, f2)!=Find(v, f2)) {
                res.push_back(pair<int, int>(u, v));
                Union(u, v, f1);
                Union(u, v, f2);
            }
        }
    }
    cout << res.size() << endl;
    for (size_t i=0; i<res.size(); i++) {
        cout << res[i].first << " " << res[i].second << endl;
    }
    return 0;
}
