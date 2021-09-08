#include <bits/stdc++.h>
using namespace std;


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    while (cin >> q) {
        // cout << q << endl;
        deque<int> q1;
        priority_queue<int, vector<int>, std::greater<int>> q2;
        for (int i=0; i<q; i++) {
            int op, x;
            cin >> op;
            if (op == 1) {
                cin >> x;
                q1.push_back(x);
            }
            else if (op == 2) {
                if (q2.empty()) {
                    cout << q1.front() << endl;
                    q1.pop_front();
                }
                else {
                    cout << q2.top() << endl;
                    q2.pop();
                }
            }
            else if (op == 3) {
                while (!q1.empty()) {
                    int t = q1.front();
                    q2.push(t);
                    q1.pop_front();
                }
            }
        }
    }
    return 0;
}
