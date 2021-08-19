#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL to_long_long(const string& s)
{
    LL res = 0;
    LL base = 1;
    // cout << s << endl;
    for (int i=s.size()-1; i>=0; i--) {
        res += base * (s[i]-'0');
        base *= 10;
        // cout << res <<endl;
    }
    return res;
}

int main()
{
    //std::ios::sync_with_stdio(false);
    //cin.tie(NULL);

    int t;
    cin >> t;
    vector<vector<LL>> ss(2, vector<LL>());
    for (int i=1; i<11; i++) {
        for (int j=1; j<10; j++) {
            string s;
            for (int k=0; k<i; k++) s+=j+'0';
            // cout << s << endl;
            ss[0].push_back(to_long_long(s));
            // cout << to_long_long(s) << endl;
        }
    }
    // for (auto& x: ss[0]) cout << x << endl;
    for (int l=1; l<11; l++) {
        for (int x=0; x<10; x++) {
            for (int y=x+1; y<10; y++) {
                for (int m=0; m<(1<<l); m++) {
                    string s; s.resize(l);
                    for (int k=0; k<l; k++) {
                        if ((m>>k)&1) s[k]=x+'0';
                        else s[k]=y+'0';
                    }
                    if (s[0] != '0') {
                        ss[1].push_back(to_long_long(s));
                        // cout << s << endl;
                    }
                }
            }
        }
    }
    sort(ss[0].begin(), ss[0].end());
    // for (auto& x: ss[0]) cout << x << endl;
    sort(ss[1].begin(), ss[1].end());
    while (t--) {
        int n, k;
        cin >> n >> k;
        auto low = lower_bound(ss[k-1].begin(), ss[k-1].end(), n);
        cout << *low << endl;
    }


    return 0;
}
