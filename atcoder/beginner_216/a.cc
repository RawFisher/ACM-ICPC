#include <bits/stdc++.h>
using namespace std;


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    double x;
    while (cin >> x) {
        int y = (int(x * 10)) % 10;
        if (y >= 0 && y <= 2) {
            cout << int(x) << "-\n";
        }
        else if (y >= 3 && y <= 6) {
            cout << int(x) << "\n";
        }
        else if (y >= 7 && y <= 9) {
            cout << int(x) << "+\n";
        }
    }
    return 0;
}
