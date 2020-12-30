// link: https://codeforces.com/contest/1435/problem/D
// 题目大意
// 有n个数，1到n。依次输入2n个字符，当字符为'+'时，表示把其中一个数放入集合，
// 当字符为'-'时，表示把集合中最小的数取出来。
// 现在已知每次字符为'-'时取出的数是多少，问当字符为'+'时，输入的数是多少？
// 存在可行方案输出YES还有顺序n个输入的数
// 没有可行方案输出NO。
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int n, num;

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
  freopen("D_input.txt", "r", stdin);
  // freopen("D_output.txt", "w", stdout);
#endif

  while (cin >> n) {
    // 当碰到一个'+'时，显然需要把他放到最近的一个'-'上，
    // 因为最近的受到的（不等式）约束越少。
    // 具体实现中，需要倒着扫描输入，
    // 设一个最小堆，当遇到'+'时，输入数字必须大于最小堆的堆顶，
    // 遇到'-'时，把最小堆的堆顶放入结果数组中并pop出来。
    // 存在解的话倒序输出结果数组。
    // 实际上使用栈也能达到最小堆的效果
    bool consis = true;
    vector<int> res, a;
    stack<int> s;
    for (int i = 0; i < 2 * n; i++) {
      char c;
      cin >> c;
      if (c == '-') { cin >> num; a.push_back(num); }
      else a.push_back(0);
    }
    for (int i = 2*n-1; i >= 0; i--) {
      if (a[i] != 0) {
        if (!s.empty() && s.top() < a[i]) { consis = false; break; }
        s.push(a[i]);
      }
      else {
        if (!s.empty()) {
          res.push_back(s.top());
          s.pop();
        }
        else { consis = false; break; }
      }
    }
    if (consis) {
      cout << "YES\n";
      reverse(res.begin(), res.end()); // 用codeforce的clang++编译会超时
      for (const int &x: res) cout << x << " ";
      // for (int i = n-1; i >= 0; i--) cout << res[i] << " ";
      cout << "\n";
    }
    else {
      cout << "NO\n";
    }
  }
  return 0;
}
