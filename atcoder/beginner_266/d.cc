#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

typedef long long ll;
static const int N = 100000 + 5;

int main()
{
  int n; cin >> n;
  unordered_map<int, pair<int, int>> balls;
  for (int i=0; i<n; i++) {
    int t, x, a;
    cin >> t >> x >> a;
    balls[t] = make_pair(x, a);
  }
  vector<vector<ll>> f(N, vector<ll>(5, 0));
  if (balls[0].first == 0) {
    f[0][0] = balls[0].second;
  }
  for (int i=1; i<N; i++) {
    for (int j=0; j<5; j++) {
      if (j>=1 && i>=j) f[i][j]=max(f[i][j], f[i-1][j-1]);
      if (j<=3 && i>=j+1) f[i][j]=max(f[i][j], f[i-1][j+1]);
      if (i>=j) f[i][j] = max(f[i-1][j], f[i][j]);
    }
    if (!balls.count(i)) {
      continue;
    }
    int ind = balls[i].first;
    if (i>=ind) f[i][ind] += balls[i].second;
  }
  // for (int i=0; i<=5; i++)
  //   printf("%lld %lld %lld %lld %lld\n", f[i][0],f[i][1],f[i][2],f[i][3],f[i][4]);
  cout << max({f[N-1][0], f[N-1][1], f[N-1][2], f[N-1][3], f[N-1][4]}) << endl;;
  return 0;
}