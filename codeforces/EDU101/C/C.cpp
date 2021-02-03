#include <bits/stdc++.h>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("../../../../C/input.txt", "r", stdin);
	freopen("../../../../C/output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		bool posible = true;
		int l = 0, r = 0;
		int h;
		for (int i = 0; i < n; i++) {
			cin >> h;
			if (!posible) continue;
			if (i == 0) l = r = h;
			else {
				l = max(h, l - (k - 1));
				r = min(h + (k - 1), r + (k - 1));
				// cout << l << " " << r << endl;
				if (l > r) { posible = false; }
			}
		}
		if (!(h <= r && h >= l)) posible = false;
		if (posible) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
