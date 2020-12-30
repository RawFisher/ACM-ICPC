#include <iostream>
#include <map>
using namespace std;

typedef long long ll;

ll cost[4], num[4] = {2, 3, 5, 1};
map<ll, ll> dp;

ll dfs(ll sum) {
  // cout << sum << endl;
  if (sum == 0) return 0;
  if (sum == 1) return cost[3];
  if (dp.count(sum)) return dp[sum];
  ll res = 1e18;
  if (sum < res / cost[3]) res = sum * cost[3];
  for (int i = 0; i < 3; i++) {
    ll c1 = 0, c2 = 0;
    ll a = num[i];
    ll t = sum;
    while (t % a != 0) {
      c1 += cost[3];
      t--;
    }
    if (t != 0) {
      c1 += cost[i];
      t /= a;
    }
    c1 += dfs(t);
    t = sum;
    while (t % a != 0) {
      c2 += cost[3];
      t++;
    }
    c2 += cost[i];
    t /= a;
    c2 += dfs(t);
    res = min(res, min(c1, c2));
  }
  dp[sum] = res;
  return res;
}

int main()
{
  int t;
  cin >> t;
  while (t--) {
    dp.clear();
    ll n;
    cin >> n;
    for (int i = 0; i < 4; i++) {
      cin >> cost[i];
    }
    cout << dfs(n) << "\n";
  }
  return 0;
}