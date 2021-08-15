#include <bits/stdc++.h>
using namespace std;

typedef long long LL;


void prosses(vector<int> &a, int l, int r) {
    for (int i=0; i<=r-l; i++) {
        a[l+i] = a[l+i] & a[r-i];
    }
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
        vector<int> a(n);
        for (int i=0; i<n; i++) cin >> a[i];
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                prosses(a, i, j);
            }
        }
        int max_v = a[0];
        for (int i=1; i<n; i++) {
            if (max_v < a[i]) max_v = a[i];
        }
        cout << max_v << endl;
    }
    return 0;
}
