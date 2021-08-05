#include <bits/stdc++.h>
using namespace std;

const int N = 100000 + 10;
int a[N];

int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    for (int i=0; i<n; i++) cin >> a[i];
    long long res = -1e9+10;
    for (int i=max(0, n-2*k); i<n; i++) {
      for (int j=i+1; j<n; j++) {
	long long tmp = (long long)1*(i+1)*(j+1) - k*(a[i]|a[j]);
	res = max(res, tmp);
      }
    }

    cout << res << endl;
  }

  return 0;
}
