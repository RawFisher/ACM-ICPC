#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        long long tot = 0;
        long long p = 0;
        for (int i=0; i<n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        for (int i=0; i<n; i++) {
            p += a[i];
            if (x >= p) tot += (x-p)/(i+1) + 1;
        }
        cout << tot << "\n";
    }
    return 0;
}