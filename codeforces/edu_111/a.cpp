#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int s;
        cin >> s;
        int tot = 1, len = 1, cur = 1;
        while (tot < s) {
            cur += 2;
            tot += cur;
            len++;
        }
        cout << len << endl;
    }
    return 0;
}
