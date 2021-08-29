#include <bits/stdc++.h>
using namespace std;


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin >> n) {
        vector<pair<string, string>> c;
        for (int i=0; i<n; i++) {
            pair<string, string> t;
            cin >> t.first >> t.second;
            c.push_back(t);
        }
        bool found = false;
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                if (c[i].first==c[j].first && c[i].second==c[j].second) {
                    found = true;
                    break;
                }
            }
        }
        if (found) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
