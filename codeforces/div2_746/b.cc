#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int i=0; i<n; i++) {
            cin >> a[i];
        }
        if (n >= 2*x) {
            cout << "YES\n";
        }
        else {
            vector<int> b = a;
            sort(b.begin(), b.end());
            bool has = true;
            for (int i=n-x; i<x; i++) {
                if (a[i] != b[i]) {
                    has = false;
                    break;
                }
            }
            if (has) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}
