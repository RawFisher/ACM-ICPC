#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    while (cin >> s) {
        int n = s.length();
        bool flag = true;
        int na = 0, nb = 0, nc = 0;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] > s[i+1]) { flag = false; break; }
        }
        if (!flag) { printf("NO\n"); }
        else {
            for (int i = 0; i < n; i++) {
                if (s[i] == 'a') na++;
                else if (s[i] == 'b') nb++;
                else if (s[i] == 'c') nc++;
            }
            if (na && nb && (na == nc || nb == nc)) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}
