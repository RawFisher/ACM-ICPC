#include <bits/stdc++.h>
using namespace std;


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        while (1) {
            bool finish = true;
            bool all = true;
            for (int i=0; i<n; i++) {
                if (s[i]=='?') {finish=false; break;}
            }
            for (int i=0; i<n; i++) {
                if (s[i]!='?') all=false;
            }
            if (finish) break;
            if (all) {
                s[0] = 'B';
            }
            for (int i=0; i<n; i++) {
                if (s[i] == '?') {
                    if ((i>0 && s[i-1]!='?')) {
                        if (s[i-1]=='R') s[i] = 'B';
                        else s[i] = 'R';
                    }
                    else if (i<n-1 && s[i+1]!='?') {
                        if (s[i+1]=='R') s[i] = 'B';
                        else s[i] = 'R';
                    }
                }
            }
        }
        cout << s << endl;
    }
    return 0;
}
