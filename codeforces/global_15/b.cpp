#include <bits/stdc++.h>
using namespace std;

const int N = 50000 + 10;
int r[N][5];

int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
      for (int j=0; j<5; j++) {
	cin >> r[i][j];
      }
    }
    int winer = 0;
    for (int i=1; i<n; i++) {
      int tot = 0;
      for (int j=0; j<5; j++) {
	if (r[i][j] < r[winer][j]) tot++;
	if (tot >= 3) { winer=i; break; }
      }
    }
    for (int i=0; i<n; i++) {
      if (i != winer) {
	int tot = 0;
	for (int j = 0; j<5; j++) {
	  if (r[winer][j] < r[i][j]) tot++;
	}
	if (tot < 3) { winer=-2; break; }
      }
    }
    cout << winer + 1 << endl;
  }

  return 0;
}
