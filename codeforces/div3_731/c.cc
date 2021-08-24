#include <bits/stdc++.h>
using namespace std;


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int k, n, m;
        cin >> k >> n >> m;
        vector<int> a(n);
        vector<int> b(m);
        vector<int> res(n+m);
        for (int i=0; i<n; i++) cin >> a[i];
        for (int i=0; i<m; i++) cin >> b[i];
        int i=0, j=0;
        bool exist=true;
        while (i+j<n+m) {
            if (i<n && a[i]==0) {res[i+j]=a[i];i++;k++;}
            else if (j<m && b[j]==0) {res[i+j]=b[j];j++;k++;}
            else if (i<n && a[i]<=k) {res[i+j]=a[i];i++;}
            else if (j<m && b[j]<=k) {res[i+j]=b[j];j++;}
            else {exist=false; break;}
        }
        if (exist) {
            for (int i=0; i<n+m; i++) cout << res[i] << " ";
            cout << endl;
        }
        else {
            cout << "-1\n";
        }
    }
    return 0;
}
