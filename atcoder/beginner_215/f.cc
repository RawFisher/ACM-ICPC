#include <bits/stdc++.h>
using namespace std;


bool judge(const vector<pair<int, int>>& points, int value)
{
    int miny = (int)(1e9+10);
    int maxy = 0;
    queue<pair<int, int>> q;
    for (auto& p: points) {
        while (!q.empty()) {
            auto& front= q.front();
            if (front.first > p.first-value) break;
            miny = min(miny, front.second);
            maxy = max(maxy, front.second);
            q.pop();
        }
        if (miny <= p.second-value || maxy >= p.second+value) return true;
        q.push(p);
    }
    return false;
}


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin >> n) {
        vector<pair<int, int>> ps;
        for (int i=0; i<n; i++) {
            pair<int, int> p;
            cin >> p.first >> p.second;
            ps.push_back(p);
        }
        sort(ps.begin(), ps.end());
        // for (auto& x: ps) {
        //     cout << x.first << " " << x.second << endl;
        // }

        int l=0, r=(int)(1e9+10);
        while (l + 1 < r) {
            int m = l+((r-l)>>1);
            // cout << m << endl;
            if (judge(ps, m)) {
                l = m;
            }
            else {
                r = m;
            }
        }
        cout << l << endl;
    }

    return 0;
}
