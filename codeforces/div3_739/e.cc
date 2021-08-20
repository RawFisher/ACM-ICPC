#include <bits/stdc++.h>
using namespace std;

typedef long long LL;


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string t;
        cin >> t;
        string order;
        for (int i=t.size()-1; i>=0; i--) {
            char x = t[i];
            bool repeat = false;
            for (auto& o: order) {
                if (x == o) {repeat = true;break;}
            }
            if (!repeat) order.push_back(x);
        }
        reverse(order.begin(), order.end());
        // cout << order << endl;

        vector<int> tot(26, 0);
        for (int i=0; i<t.size(); i++) {
            tot[t[i]-'a']++;
        }
        bool succ = true;
        for (int i=0; i<order.size(); i++) {
            if (!(tot[order[i]-'a']%(i+1)==0)) {
                succ = false;
                break;
            }
            tot[order[i]-'a'] /= (i + 1);
        }
        if (!succ) {
            cout << "-1\n";
            continue;
        }
        string res;
        vector<int> tot2(26, 0);
        for (int i=0; i<t.size(); i++) {
            if (tot2[t[i]-'a']==tot[t[i]-'a']) {
                break;
            }
            tot2[t[i]-'a']++;
            res.push_back(t[i]);
        }
        string new_res = res;
        string new_tmp = res;
        for (int i=0; i<order.size(); i++) {
            string ss = new_tmp;
            char x = order[i];
            string new_ss;
            for (auto& cc: ss) {
                if (cc != x) new_ss.push_back(cc);
            }
            new_tmp = new_ss;
            new_res += new_ss;
        }
        if (new_res == t) {
            cout << res << " " << order << endl;
        } else {
            cout << "-1\n";
        }
    }
    return 0;
}
