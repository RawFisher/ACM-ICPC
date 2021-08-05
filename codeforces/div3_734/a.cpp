#include <bits/stdc++.h>
using namespace std;

int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int t = n / 3;
    if (n % 3 <= 1) {
      int c2 = t;
      int c1 = n - 2 * c2;
      cout << c1 << " " << c2 << endl;
    } else {
      int c1 = t;
      int c2 = (n - c1) / 2;
      cout << c1 << " " << c2 << endl;
    }
  }

  return 0;
}
