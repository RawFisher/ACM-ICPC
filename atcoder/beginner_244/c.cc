#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<bool> vis(2*n+2, false);
    while (true) {
        for (int i=1; i<=2*n+1; i++) {
            if (!vis[i]) {
                cout << i << endl;
                vis[i] = true;
                break;
            }
        }
        int input;
        cin >> input;
        if (input == 0) {
            break;
        }
        vis[input] = true;
    }
    return 0;
}
