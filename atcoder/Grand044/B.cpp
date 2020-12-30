#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;


const int N = 500 + 5;

int n;
int movex[] = {0, -1, 0, 1};
int movey[] = {-1, 0, 1, 0};
int occ[N][N], f[N][N];

void dp(int x, int y) {
  if (!x || !y || x > n || y > n) return;
  for (int i = 0; i < 4; i++) {
    int tx = x + movex[i];
    int ty = y + movey[i];
    if (occ[x][y] + f[x][y] < f[tx][ty]) {
      f[tx][ty] = occ[x][y] + f[x][y];
      // printf("change!\n");
      dp(tx, ty);
    }
  }
}

int main()
{
  while (scanf("%d", &n) != EOF) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        occ[i][j] = 1;
        int temp[] = {i-1, j-1, n-i, n-j};
        f[i][j] = *min_element(temp, temp + 4);
      }
    }
    int hate = 0;
    for (int i = 1; i <= n*n; i++) {
      int p, row, col;
      scanf("%d", &p);
      row = (p - 1) / n + 1;
      col = (p + n - 1) % n + 1;
      // printf("%d %d\n", row, col);
      occ[row][col] = 0;
      hate += f[row][col];
      // printf("hate=%d\n", hate);
      dp(row, col);
    }
    printf("%d\n", hate);
  }
  return 0;
}