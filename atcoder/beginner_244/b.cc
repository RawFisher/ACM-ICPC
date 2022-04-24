#include <iostream>
#include <string>
using namespace std;

int movex[] = {1, 0, -1, 0};
int movey[] = {0, -1, 0, 1};

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string t;
    cin >> n >> t;
    int face = 0;
    int x = 0, y = 0;
    for (auto c: t) {
        if (c == 'S') {
            x += movex[face];
            y += movey[face];
        }
        else if (c == 'R') {
            face = (face + 1) % 4;
        }
    }
    cout << x << " " << y << endl;

    return 0;
}
