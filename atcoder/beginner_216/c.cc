#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    LL n;
    while (cin >> n) {
        string res;
        while (n) {
            if (n % 2 == 0) {
                n /= 2;
                res.push_back('B');
            }
            else {
                n -= 1;
                res.push_back('A');
            }
        }
        reverse(res.begin(), res.end());
        cout << res << endl;
    }
    return 0;
}
