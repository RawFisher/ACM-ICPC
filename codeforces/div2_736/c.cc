#include <iostream>
#include <vector>
using namespace std;


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> big(n+1, 0);
    int res = 0;
    for (int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        big[min(u, v)]++;
    }
    for (int i=1; i<=n; i++) {
        if (big[i] == 0) res++;
    }
    int q;
    cin >> q;
    for (int i=0; i<q; i++) {
        int o;
        cin >> o;
        if (o == 3) {
            cout << res << endl;
        } else if (o == 1) {
            int u, v;
            cin >> u >> v;
            big[min(u, v)]++;
            if (big[min(u, v)] == 1) res--;
        } else {
            int u, v;
            cin >> u >> v;
            big[min(u, v)]--;
            if (big[min(u, v)] == 0) res++;
        }
    }
    return 0;
}
