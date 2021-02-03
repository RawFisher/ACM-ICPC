#include <bits/stdc++.h>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("../../../../A/input.txt", "r", stdin);
	freopen("../../../../A/output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int l = s.length();
		if (l % 2) cout << "NO" << endl;
		else if (s[0] == ')' || s[l - 1] == '(') cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	return 0;
}
