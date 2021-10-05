#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, h;
        cin >> n >> h;
        vector<int> w(n);
        for (int i=0; i<n; i++) {
            cin >> w[i];
        }
        sort(w.begin(), w.end());
        reverse(w.begin(), w.end());
        int a = w[0], b = w[1];
        if (h%(a+b)) {
            if (h%(a+b) > max(a, b)) {
                cout << h/(a+b)*2 + 2 << endl;
            }
            else {
                cout << h/(a+b)*2 + 1 << endl;
            }
        }
        else {
            cout << h/(a+b)*2 << endl;
        }
    }
    return 0;
}
