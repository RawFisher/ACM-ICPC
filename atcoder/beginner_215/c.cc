#include <bits/stdc++.h>
using namespace std;


void get_all(vector<string> &ss, string& s, vector<int> &ind, string& get)
{
    if (get.size() == s.size()) ss.push_back(get);
    for (int i=0; i<ind.size(); i++) {
        if (!ind[i]) {
            get.push_back(s[i]);
            ind[i] = 1;
            get_all(ss, s, ind, get);
            get.pop_back();
            ind[i] = 0;
        }
    }
}


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    int k;
    while (cin >> s >> k) {
        vector<string> ss;
        vector<int> used(s.size(), 0);
        string tmp;
        get_all(ss, s, used, tmp);
        sort(ss.begin(), ss.end());
        auto it = unique(ss.begin(), ss.end());
        // for (auto& x: ss) cout << x << endl;
        cout << ss[k-1] << endl;
    }
    return 0;
}
