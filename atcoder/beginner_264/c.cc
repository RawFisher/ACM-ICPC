#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int h1,w1,h2,w2;
  cin>>h1>>w1;
  vector<vector<int>> a(h1, vector<int>(w1));
  for (int i=0; i<h1; i++) {
    for (int j=0; j<w1; j++) {
      cin >> a[i][j];
    }
  }
  cin>>h2>>w2;
  vector<vector<int>> b(h1, vector<int>(w1));
  for (int i=0; i<h2; i++) {
    for (int j=0; j<w2; j++) {
      cin >> b[i][j];
    }
  }
  if (h1<h2 || w1<w2) {
    cout << "No\n";
    return 0;
  }
  for (int i=0; i<(1<<h1); i++) {
    for (int j=0; j<(1<<w1); j++) {
      vector<int> x, y;
      for (int k=0; k<h1; k++) if (i&(1<<k)) x.push_back(k);
      for (int k=0; k<w1; k++) if (j&(1<<k)) y.push_back(k);
      if (x.size()!=h2 || y.size()!=w2) {
        continue;
      }
      bool match = true;
      for (int c=0; c<h2; c++) {
        for (int d=0; d<w2; d++) {
          if (b[c][d] != a[x[c]][y[d]]) {
            match = false;
            break;
          }
        }
        if (!match) break;
      }
      if (match) {
        cout << "Yes\n"; return 0;
      } else {
        continue;
      }
    }
  }
  cout << "No\n";
  return 0;
}