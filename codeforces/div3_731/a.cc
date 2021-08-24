#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int xa, ya, xb, yb, xf, yf;
        cin >> xa >> ya >> xb >> yb >> xf >> yf;
        int minx = min(xa, xb);
        int miny = min(ya, yb);
        int maxx = max(xa, xb);
        int maxy = max(ya, yb);
        int ans = maxx-minx + maxy-miny;
        if ((minx==maxx && xf==minx && yf<=maxy && yf>=miny) ||
            (minx==maxx && xf==maxx && yf<=maxy && yf>=miny) ||
            (miny==maxy && yf==miny && xf<=maxx && xf>=minx) ||
            (miny==maxy && yf==maxy && xf<=maxx && xf>=minx)) {
            cout << ans + 2 << endl;
        }
        else {
            cout << ans << endl;
        }
    }
    return 0;
}
