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
        LL a, b, c;
        cin >> a >> b >> c;
        LL tot = abs(a-b) * 2;
        if (a>tot || b>tot || c>tot) {
            cout << "-1\n";
        } else {
            if (c > tot / 2) {
                cout << c - (tot / 2) << endl;
            } else {
                cout << c + (tot / 2) << endl;
            }
        }
    }
    return 0;
}