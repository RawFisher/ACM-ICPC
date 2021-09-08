#include <bits/stdc++.h>
using namespace std;


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> contest{"ABC", "ARC", "AGC", "AHC"};
    string s1, s2, s3;
    while (cin >> s1 >> s2 >> s3) {
        for (auto& x: contest) {
            bool found = false;
            if (s1 == x) found = true;
            if (s2 == x) found = true;
            if (s3 == x) found = true;
            if (!found) {
                cout << x << endl;
                break;
            }
        }
    }
    return 0;
}
