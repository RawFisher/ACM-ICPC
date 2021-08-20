#include <bits/stdc++.h>
using namespace std;

typedef long long LL;


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s = to_string(n);
        bool finish = false;
        while (1) {
            set<char> ss;
            for (unsigned int i=0; i<s.size(); i++) {
                ss.insert(s[i]);
                if (ss.size() > k) {
                    int j = i;
                    while (s[j] == '9') j--;
                    s[j]++;
                    for (unsigned int k=j+1; k<s.size(); k++) s[k]='0';
                    break;
                } else if (i == s.size()-1) {
                    cout << s << endl;
                    finish = true;
                    break;
                }
            }
            // cout << s << endl;
            if (finish) break;
        }
    }

    return 0;
}
