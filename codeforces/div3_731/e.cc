#include <bits/stdc++.h>
using namespace std;


typedef long long uLL;
const int MAX = int(1e9+1e6);


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        vector<int> t(n);
        vector<int> l(n, MAX), r(n, MAX);
        for (int i=0; i<k; i++) cin >> a[i];
        for (int i=0; i<k; i++) {
            cin >> t[i];
            l[a[i]-1] = r[a[i]-1] = t[i];
        }
        // for (int i=0; i<n; i++) {
        //     cout << l[i] <<  " ";
        // }
        // cout << endl;
        for (int i=1; i<n; i++) {
            l[i] = min(l[i], l[i-1]+1);
        }
        for (int i=n-2; i>=0; i--) {
            r[i] = min(r[i], r[i+1]+1);
        }
        for (int i=0; i<n; i++) {
            cout << min(l[i], r[i]) << " ";
        }
        cout << endl;
    }
    return 0;
}
