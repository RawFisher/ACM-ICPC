#include <bits/stdc++.h>
using namespace std;
 
typedef long long LL;
 
 
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    vector<int> a;
    int tot = 1;
    while (a.size() < 1000) {
        if (!(tot % 10 == 3 || tot % 3 == 0)) {
            a.push_back(tot);
        }
        tot++;
    }
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        cout << a[k-1] << endl;
    }
    return 0;
}