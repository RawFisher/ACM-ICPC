#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        bool flag = true;
        int last = -1;
        for (int i=s.size()-1; i>=0; i--) {
                //cout << s << endl;
            if ((s[0]==char('a'+i))) {
                //cout << s[0] << endl;
                s.erase(0, 1);
                // s.pop_front();
            }
            else if ((s[s.size()-1] == char('a'+i))) {
                //cout << s[s.size()-1] << endl;
                s.pop_back();
            }
            else {
                flag = false;
                break;
            }
        }
        if (flag) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
