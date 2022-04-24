#include <iostream>
#include <string>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    string s;
    cin >> n >> s;
    cout << s[n-1] << endl;
    return 0;
}
