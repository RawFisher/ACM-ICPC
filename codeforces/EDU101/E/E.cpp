#include <bits/stdc++.h>

using namespace std;

int get_forbid(int ll, const string& s)
{
	int l = s.length();
	int res = 0;
	for (int i = l - 1; i >= 0; i--) {
		res += (s[i] - '0') << (l - i - 1);
	}
	return ((1 << ll) - 1) - res;
}

void print_res(int kk, int ll, int v)
{
	for (int i = 0; i < kk - ll; i++) {
		cout << '0';
	}
	vector<int> rest;
	for (int i = 0; i < ll; i++) {
		rest.push_back((v >> i) & 1);
	}
	for (int i = ll - 1; i >= 0; i--) {
		cout << rest[i];
	}
	cout << endl;
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("../../../../E/input.txt", "r", stdin);
	freopen("../../../../E/output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		int z = n - k + 1;
		int suf_l = ceil(log(z + 1) / log(2));
		if (suf_l > k) cout << "NO" << endl;
		else {
			cout << "YES" << endl;
			vector<int> pre0;
			set<int> forbid;
			int l = s.length();
			for (int i = 0; i < l; i++) {
				if (s[i] == '0') pre0.push_back(i);
				else pre0.push_back(i == 0 ? -1 : pre0[i - 1]);
			}
			for (int i = l - 1; i >= k - 1; i--) {
				if (pre0[i] < 0 || i - pre0[i] + 1 > k || i - pre0[i] + 1 <= suf_l) {
					string t = s.substr(i - suf_l + 1, suf_l);
					int forbid_num = get_forbid(suf_l, t);
					forbid.insert(forbid_num);
				}
			}
			int tot = (1 << suf_l);
			// sort(forbid.begin(), forbid.end());
			for (int i = 0; i < tot; i++) {
				// int rev = tot - 1 - i;
				if (!forbid.count(i)) {
					print_res(k, suf_l, i);
					break;
				}
			}
		}
	}
	return 0;
}
