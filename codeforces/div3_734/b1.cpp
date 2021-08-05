#include <bits/stdc++.h>
using namespace std;

int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.size();
    int tot[26];
    memset(tot, 0, sizeof(tot));
    for (int i=0; i<n; i++) {
      tot[s[i]-'a']++;
    }
    cout << endl;
    int b_2=0, one=0;
    for (int i=0; i<26; i++) {
      if (tot[i]>=2) b_2++;
      else if (tot[i]==1) one++;
    }
    cout <<b_2 + one / 2 << endl;
  }

  return 0;
}
