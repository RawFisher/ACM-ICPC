#include <bits/stdc++.h>
using namespace std;


bool dfs(const vector<vector<int>> &m, unsigned int node, vector<int> &res, size_t l)
{
    // cout << "vis:" << node << endl;
    // for (int i=0; i<res.size(); i++) {
    //     cout << res[i] << " ";
    // }
    // cout << endl;
    if (res.size() == l) return true;
    for (size_t i=0; i<m[node].size(); i++) {
        int v = m[node][i];
        if (v == node) continue;
        bool repeate = false;
        for (size_t j=0; j<res.size(); j++) {
            if (res[j]==v) {repeate=true; break;}
        }
        if (!repeate) {
            res.push_back(v);
            bool finished = dfs(m, v, res, l);
            if (finished) return true;
            res.pop_back();
        }
    }
    return false;
}


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix(n+2, vector<int>());
        for (int i=1; i<n; i++) {
            matrix[i].push_back(i+1);
        }
        for (int i=1; i<=n; i++) {
            int t;
            cin >> t;
            if (t) {
                matrix[n+1].push_back(i);
            }
            else {
                matrix[i].push_back(n+1);
            }
        }
        vector<int> res;
        bool finished = false;
        for (int i=1; i<=n+1; i++) {
            res.push_back(i);
            finished = dfs(matrix, i, res, n+1);
            if (finished) break;
            else res.pop_back();
        }
        if (finished) {
            for (int i=0; i<res.size(); i++) {
                cout << res[i] << " ";
            }
            cout << "\n";
        }
        else {
            cout << "-1\n";
        }
    }
    return 0;
}
