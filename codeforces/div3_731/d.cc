#include <bits/stdc++.h>
using namespace std;


typedef long long uLL;


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i=0; i<n; i++) cin >> a[i];
        vector<int> res(n, 0);
        int p = a[0];
        for (int i=1; i<n; i++) {
            p = p | a[i];
            res[i] = p ^ a[i];
        }
        for (int i=0; i<n; i++) {
            cout << res[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
