#include <bits/stdc++.h>

using namespace std;

int solve(int x, vector<int> &a, vector<int> &b)
{
	if (x <= 2) return 0;
	int tot = 0;
	int y = ceil(sqrt(x));
	for (int i = y + 1; i < x; i++) {
		tot++;
		a.push_back(i); b.push_back(x);
	}
	tot += 2;
	a.push_back(x); b.push_back(y);
	a.push_back(x); b.push_back(y);
	tot += solve(y, a, b);
	return tot;
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("../../../../D/input.txt", "r", stdin);
	freopen("../../../../D/output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a, b;
		int m = solve(n, a, b);
		cout << m << endl;
		for (int i = 0; i < m; i++) {
			cout << a[i] << " " << b[i] << endl;
		}
	}
	return 0;
}
