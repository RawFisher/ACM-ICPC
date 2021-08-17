#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

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
        LL sum = 0;
        for (int i=0; i<n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        LL left = sum % n;
        cout << (n-left)*left << endl;
    }
    return 0;
}
