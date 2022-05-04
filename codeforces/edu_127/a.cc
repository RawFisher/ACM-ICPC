#include <bits/stdc++.h>
using namespace std;

bool judge(int ll)
{
    for (int i=0; i<=500; i++) {
        for (int j=0; j<=400; j++) {
            if (2*i+j*3 == ll) return true;
        }
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
    string s;
    cin >> s;
    int i=0, j=0;
    int l = s.size();
    bool t = true;
    for (;i<l && j<=l; ) {
        if (j<l && s[i] == s[j]) {
            j++;
        }
        else {
            int ll = j - i;
            if (!judge(ll)) {
                t = false;
                break;
            }
            i = j;
        }
    }
    if (t)
    cout << "YES\n";
    else {
        cout << "NO\n";
    }
    }
    return 0;
}