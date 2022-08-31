#include <iostream>
#include <vector>
using namespace std;

bool judge_up(int x1, int y1, int x2, int y2)
{
  return (x1*y2-y1*x2) <= 0;
}

int main()
{
  vector<pair<int, int>> a;
  for (int i=0; i<4; i++) {
    int x, y; cin >> x >> y;
    a.push_back(make_pair(x, y));
  }
  for (int i=0; i<4; i++) {
    int x1=a[(i-2+4)%4].first-a[(i-1+4)%4].first;
    int y1=a[(i-2+4)%4].second-a[(i-1+4)%4].second;
    int x2=a[i].first-a[(i-1+4)%4].first;
    int y2=a[i].second-a[(i-1+4)%4].second;
    // printf("%d %d %d", (i-2+4)%4, (i-1+4)%4, i);
    if (!judge_up(x1, y1, x2, y2)) {
      cout << "No\n";
      return 0;
    }
  }

  cout << "Yes\n";
  return 0;
}