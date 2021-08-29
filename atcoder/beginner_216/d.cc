#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 200000 + 10;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    while (cin >> n >> m) {
        vector<queue<int>> a(m, queue<int>());
        for (int i=0; i<m; i++) {
            int k;
            cin >> k;
            for (int j=0; j<k; j++) {
                int x;
                cin >> x;
                a[i].push(x);
            }
        }

        vector<vector<int>> c(N, vector<int>());
        priority_queue<pair<int, int>> q;
        for (int i=0; i<m; i++) {
            if (a[i].empty()) continue;
            auto x = a[i].front();
            c[x].push_back(i);
            q.push(pair<int, int>(c[x].size(), x));
        }

        // cout << "....\n";
        int tot = 0;
        bool imposs = false;
        while (!q.empty()) {
            auto x = q.top();
            q.pop();
            // cout << x.first << " " << x.second << endl;
            if (x.first < 2) { imposs = true; break; }
            int num = x.second;
            a[c[num][0]].pop();
            a[c[num][1]].pop();
            tot += 2;
            if (tot == n * 2) { break; imposs = false; }
            if (!a[c[num][0]].empty()) {
                int new_num = a[c[num][0]].front();
                c[new_num].push_back(c[num][0]);
                q.push(make_pair(c[new_num].size(), new_num));
            }
            if (!a[c[num][1]].empty()) {
                int new_num = a[c[num][1]].front();
                c[new_num].push_back(c[num][1]);
                q.push(make_pair(c[new_num].size(), new_num));
            }
        }
        if (!imposs) {
            cout << "Yes\n";
        }
        else {
            cout << "No\n";
        }
    }
    return 0;
}
