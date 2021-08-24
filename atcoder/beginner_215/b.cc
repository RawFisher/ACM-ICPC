#include <bits/stdc++.h>
using namespace std;


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    unsigned long long n;
    int k=0;
    unsigned long long x = 1;
    cin >> n;
    while (x <= n) {
        k++;
        x <<= 1;
    }
    cout << k-1 << endl;
    return 0;
}
