#include <bits/stdc++.h>
using namespace std;


// https://en.wikipedia.org/wiki/Fenwick_tree
class FenwickTree
{
private:
    vector<int> data;

    int get_parent(int i) const {
        return i - (i & (-i));
    }

    int get_next(int i) const {
        return i + (i & (-i));
    }

public:
    FenwickTree(int n): data(n, 0) {}

    int get_sum(int i) const {
        int sum = data[0];
        while (i > 0) {
            sum += data[i];
            i = get_parent(i);
        }
        return sum;
    }

    int range_sum(int i, int j) const {
        if (i == 0) return get_sum(j);
        else return get_sum(j) - get_sum(i-1);
    }

    void add(int i, int v) {
        if (i == 0) {
            data[0] += v;
            return ;
        }
        int n = data.size();
        while (i < n) {
            data[i] += v;
            i = get_next(i);
        }
    }

    vector<int> invert() {
        vector<int> a(data);
        int n = data.size();
        for (int i=n-1; i>0; --i) {
            int j = get_next(i);
            if (j < n) a[j] -= a[i];
        }
        return a;
    }
};


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    while (cin >> n >> m) {
        FenwickTree t(n);
        vector<vector<int>> cond(m, vector<int>(3));
        for (int i=0; i<m; ++i) {
            int l, r, x;
            cin >> l >> r >> x;
            cond[i][0] = l-1;
            cond[i][1] = r-1;
            cond[i][2] = x;
        }
        sort(cond.begin(), cond.end(), [](vector<int>& a, vector<int>& b) {
                                           return a[1] < b[1];
                                       });
        for (auto& c: cond) {
            int l=c[0], r=c[1], x=c[2];
            int sum = t.range_sum(l, r);
            // cout << l << " " << r << " " << x << endl;
            // cout << sum << endl;
            if (sum < x) {
                int left = x - sum;
                for (int i=r; left && i>=0; --i) {
                    if (t.range_sum(i, i) != 1) {
                        t.add(i, 1);
                        left--;
                    }
                }
            }
            // vector<int> res = t.invert();
            // for (int i=0; i<n; ++i) {
            //     cout << res[i] << " ";
            // }
            // cout << endl;
        }

        vector<int> res = t.invert();
        for (int i=0; i<n; ++i) {
            cout << res[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
