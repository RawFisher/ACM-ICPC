#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
  char s[] = "atcoder";
  int l, r;
  cin >> l >> r;
  for (int i=l-1; i<r; i++) {
    cout << s[i];
  }
  cout << endl;
  return 0;
}