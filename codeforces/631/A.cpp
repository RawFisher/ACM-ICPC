#include <bits/stdc++.h>

typedef long long ll;

constexpr int N = 100000 + 10;
int l[N];
ll suf[N];
int n, m;
ll tot;

int main()
{
  std::cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    std::cin >> l[i];
    if (n - l[i] < i - 1) {
      std::cout << "-1\n";
      return 0;
    }
  }
  for (int i = m; i > 0; i--) {
    tot += l[i];
    suf[i] = suf[i+1] + l[i];
  }
  if (tot < n) {
    std::cout << "-1\n";
    return 0;
  }
  for (int i = 1; i <= m; i++) {
    int pos = std::max((ll)i, n-suf[i]+1);
    if (i == m) {
      std::cout << pos << "\n";
    } else {
      std::cout << pos << " ";
    }
  }
  return 0;
}
