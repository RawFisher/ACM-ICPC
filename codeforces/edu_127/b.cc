#include <bits/stdc++.h>
using namespace std;

bool judge(int b, const vector<int> &x)
{
    int l = x.size();
    int now = b;
    for (int i=1; i<l; i++) {
        if (x[i]-now>2) return false;
        now++;
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> x(n);
        for (int i=0; i<n; i++) {
            cin >> x[i];
        }
        bool can = false;
        if (judge(x[0]-1, x)) can=true;
        if (judge(x[0], x)) can = true;
        if (judge(x[0]+1, x)) can = true;
        if (can) {
            cout << "YES\n";
        }
        else cout << "NO\n";
    }
    return 0;
}