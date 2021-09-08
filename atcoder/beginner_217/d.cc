#include <bits/stdc++.h>
using namespace std;


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int l, q;
    while (cin >> l >> q) {
        set<int> cut;
        cut.insert(0);
        cut.insert(l);
        for (int i=0; i<q; i++) {
            int c, x;
            cin >> c >> x;
            if (c == 1) {
                cut.insert(x);
            }
            else {
                auto a = upper_bound(cut.begin(), cut.end(), x);
                int t1 = *a;
                int t2 = *(--a);
                cout << t1 - t2 << endl;
            }
        }
    }
    return 0;
}
