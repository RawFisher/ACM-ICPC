#include <bits/stdc++.h>
using namespace std;


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    const int N = 1e5+10;
    vector<int> prime(N, 1);
    for (int i=2; i<N; i++) {
        if (prime[i]) {
            for (int j=2; j<=N/i; j++) {
                prime[i*j] = 0;
            }
        }
    }
    vector<int> p;
    for (int i=2; i<N; i++) {
        if (prime[i]) p.push_back(i);
    }
    // cout << p.size() << endl;
    int n, m;
    while (cin >> n >> m) {
        vector<int> a(n);
        vector<int> res(m+1, 1);
        for (int i=0; i<n; i++) {
            cin >> a[i];
            vector<int> pp;
            for (int j=2; j*j<=a[i]; j++) {
                while (a[i] % j == 0) {
                    a[i] /= j;
                    pp.push_back(j);
                }
            }
            if (a[i] != 1) pp.push_back(a[i]);
            for (auto& x: pp) {
                if (x<=m && res[x]) {
                    for (int j=x; j<=m; j+=x) res[j]=0;
                }
            }
        }
        vector<int> r;
        for (int i=1; i<=m; i++) {
            if (res[i]) r.push_back(i);
        }
        cout << r.size() << endl;
        for (auto &x: r) {
            cout << x << endl;
        }
    }

    return 0;
}
