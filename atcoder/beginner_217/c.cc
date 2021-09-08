#include <bits/stdc++.h>
using namespace std;


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin >> n) {
        vector<int> a(n);
        vector<int> q(n);
        for (int i=0; i<n; i++) {
            cin >> a[i];
            q[a[i]-1] = i + 1;
        }
        for (int& x: q) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}
