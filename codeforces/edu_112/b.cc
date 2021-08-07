#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int w, h, x1, y1, x2, y2, w2, h2, rw, rh;
        cin >> w >> h;
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> w2 >> h2;
        rw = x2 - x1;
        rh = y2 - y1;
        if (rw+w2>w && rh+h2>h) cout << -1 << endl;
        else {
            int m1, m2, m3, m4;
            if (rw+w2<=w && rh+h2>h) {
                m1 = max(0, w2-x1);
                m2 = max(0, x2-(w-w2));
                cout << min(m1, m2) << endl;
            }
            else if (rw+w2>w && rh+h2<=h) {
                m1 = max(0, h2-y1);
                m2 = max(0, y2-(h-h2));
                cout << min(m1, m2) << endl;
            }
            else {
                // rw+w2<=w && rh+h2<=h
                m1 = max(0, w2-x1);
                m2 = max(0, x2-(w-w2));
                m3 = max(0, h2-y1);
                m4 = max(0, y2-(h-h2));
                cout << min(m1, min(m2, min(m3, m4))) << endl;
            }
        }
    }
    return 0;
}
