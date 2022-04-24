#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    char s1, s2, s3;
    char t1, t2, t3;

    cin >> s1 >> s2 >> s3;
    cin >> t1 >> t2 >> t3;
    if (s1==t1 && s2==t2 && s3==t3) {
        cout << "Yes\n";
    }
    else if (s1==t3 && s2==t1 && s3==t2) {
        cout << "Yes\n";
    }
    else if (s1==t2 && s2==t3 && s3==t1) {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
    }
    return 0;
}
