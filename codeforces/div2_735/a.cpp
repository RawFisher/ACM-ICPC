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
    int n;
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    long long res = -1;
    for (int i=0; i<n; i++) {
      if (i>0) res = max(res, (long long)a[i]*a[i-1]);
      if (i<n-1) res = max(res, (long long)a[i]*a[i+1]);
    }

    cout << res << endl;
  }

    

  return 0;
}
