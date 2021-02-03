#include <bits/stdc++.h>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("../../../../B/input.txt", "r", stdin);
	freopen("../../../../B/output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		int max_bp = 0, max_ap = 0;
		int pre_a = 0, pre_b = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			pre_a += num;
			max_ap = max(max_ap, pre_a);
		}
		cin >> m;
		for (int i = 0; i < m; i++) {
			int num;
			cin >> num;
			pre_b += num;
			max_bp = max(max_bp, pre_b);
		}
		cout << max_ap + max_bp << endl;
	}
	return 0;
}
