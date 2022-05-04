#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 998244353

int mod(int x, int y)
{
    return (1ll * x * y) % MOD;
}

pair<int, string> dfs(const string &s, int v)
{
    int n = s.length();
    if (v*2+1 >= n) return make_pair(1, string(1, s[v]));
    pair<int, string> l = dfs(s, v*2+1);
    pair<int, string> r = dfs(s, v*2+2);
    if (l.second == r.second) {
        return make_pair(mod(l.first, l.first), s[v]+l.second+l.second);
    }
    else {
        string m = min(s[v]+l.second+r.second, s[v]+r.second+l.second);
        return make_pair(mod(2, mod(l.first, r.first)), m);
    }
}

int main()
{
    int n;
    string s;
    cin >> n;
    cin >> s;
    pair<int, string> res = dfs(s, 0);
    cout << res.first << endl;
    return 0;
}