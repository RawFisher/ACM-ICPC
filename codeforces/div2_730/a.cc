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
        LL a, b;
        cin >> a >> b;
        if (a == b) {
            cout << "0 0\n";
        }
        else {
            LL ans = abs(a - b);
            LL step = a % ans;

            LL step2 = ans - (min(a, b) % ans);
            cout << ans << " " << min(step, step2) << endl;
        }
        // for (int i=0; i<10; i++) {
        //     cout << a+i << " " << b+i << " " << gcd(a+i, b+i) << endl;
        // }
        // for (int i=0; i<min(a,b); i++) {
        //     gcd(a-i, b-i);
        // }
    }
    return 0;
}
