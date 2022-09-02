#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> g(n, vector<char>(m));
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> g[i][j];
        }
    }
    int x=0, y=0;
    while (1) {
        vis[x][y] = true;
        int p_x=x, p_y=y;
        switch (g[x][y]) {
            case 'U': {x-=1; break;}
            case 'D': {x+=1; break;}
            case 'L': {y-=1; break;}
            case 'R': {y+=1; break;}
            default : break;
        }
        // printf("%c (%d %d)=>(%d %d)\n", g[p_x][p_y], p_x, p_y, x, y);
        if (x<0||y<0||x>=n||y>=m) {
            cout << p_x+1 << " " << p_y+1 << endl;
            break;
        }
        if (vis[x][y]) {
            cout << "-1\n";
            break;
        }
    }
    return 0;
}
