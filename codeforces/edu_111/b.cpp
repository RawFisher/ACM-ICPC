#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        string s;
        cin >> s;
        int tot = a * n;
        if (b > 0) {
            cout << tot + n * b << endl;
        } else {
            int parts = 1, pre = s[0];
            for (int i=1; i<n; i++) {
                if (s[i] != pre) parts++, pre=s[i];
            }
            if (parts > 2) cout << n * a + (parts / 2 + 1) * b << endl;
            else cout << n * a + parts * b << endl;
        }
    }
    return 0;
}
