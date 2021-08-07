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
        long long n;
        cin >> n;
        while (n<6 || n%2!=0) n++;
        cout << LL(n*2.5+0.5) << endl;
    }
    return 0;
}
