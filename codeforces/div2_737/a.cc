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
        vector<int> a(n);
        long long sum = 0;
        for (int i=0; i<n; i++) cin >> a[i], sum+= a[i];
        sort(a.begin(), a.end());
        int last = a[n-1];
        double res = 1.0*(sum-last)/(n-1)+last;
        printf("%.8f\n", res);
        // cout << 1.0*(sum-last)/(n-1)+last << endl;
    }
    return 0;
}
