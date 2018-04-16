#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int main() {
    int n, k, k1, k2;
    while (scanf("%d%d%d", &n, &k1, &k2) != EOF) {
        k = k1 + k2;
        vector<int> a, b;
        for (int i = 0; i < n; i++) {
            int x; scanf("%d", &x);
            a.push_back(x);
        }
        for (int i = 0; i < n; i++) {
            int x; scanf("%d", &x);
            b.push_back(x);
        }
        priority_queue<int> q;
        for (int i = 0; i < n; i++) q.push(abs(a[i] - b[i]));
        for (int i = 0; i < k; i++) {
            int t = q.top(); q.pop();
            if (t > 0) t -= 1;
            else if (t == 0) t += 1;
            q.push(t);
        }
        long long ans = 0;
        while (!q.empty()) {
            int t = q.top(); q.pop();
            ans += 1LL * t * t;
        }
        cout << ans << endl;
    }
    return 0;
}
