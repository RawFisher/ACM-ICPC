#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF=(ll)1e11+10;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<ll> a(n);
        ll tot = 0;
        for (int i=0; i<n; i++) {
            cin >> a[i];
            if (i>=1) tot += abs(a[i]-a[i-1]);
        }
        ll ans = tot+abs(a[0]-x)+x-1;
        ll min_p=abs(a[0]-1);
        for (int i=0; i<n-1; i++) {
            ans=min(ans, min_p+tot-abs(a[i+1]-a[i])+abs(a[i+1]-x)+abs(a[i]-x));
            ans=min(ans, tot-abs(a[i+1]-a[i])+abs(a[i+1]-x)+abs(1-a[i])+(x-1));
            min_p=min(min_p, abs(1-a[i])+abs(a[i+1]-1)-abs(a[i+1]-a[i]));
        }
        ans=min(ans, min_p+tot+abs(x-a[n-1]));
        ans=min(ans, tot+abs(1-a[n-1])+(x-1));
        reverse(a.begin(), a.end());
        ans = min(ans, tot+abs(a[0]-x)+x-1);
        min_p=abs(a[0]-1);
        for (int i=0; i<n-1; i++) {
            ans=min(ans, min_p+tot-abs(a[i+1]-a[i])+abs(a[i+1]-x)+abs(a[i]-x));
            ans=min(ans, tot-abs(a[i+1]-a[i])+abs(a[i+1]-x)+abs(1-a[i])+(x-1));
            min_p=min(min_p, abs(1-a[i])+abs(a[i+1]-1)-abs(a[i+1]-a[i]));
        }
        ans=min(ans, min_p+tot+abs(x-a[n-1]));
        ans=min(ans, tot+abs(1-a[n-1])+(x-1));
        cout << ans << endl;
    }
    return 0;
}