#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    vector<string> b;
    for (LL i=0; i<60; i++) {
        LL num = 1LL << i;
        b.push_back(to_string(num));
    }
    while (t--) {
        string s;
        cin >> s;
        unsigned int res = 10000;
        for (const string& num: b) {
            unsigned int i=0, j=0;
            for (; i<s.size(); i++) {
                if (j<num.size() && s[i]==num[j]) j++;
            }
            // cout << num << " " << j << endl;
            unsigned int t_res = num.size()-j + (s.size()-j);
            // cout << num << " " << t_res << endl;
            res = min(res, t_res);
        }
        cout << res << endl;
    }
    return 0;
}
