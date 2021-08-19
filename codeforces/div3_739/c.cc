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
        int k;
        cin >> k;
        int s = 1;
        while (s*s < k) {
            s++;
        }
        int l = k-(s-1)*(s-1);
        int tot = s*s-(s-1)*(s-1);
        if (l>tot/2) {
            cout << s << " " << s*s-k+1 << endl;
        } else {
            cout << k-(s-1)*(s-1) << " " << s << endl;
        }
    }
    return 0;
}