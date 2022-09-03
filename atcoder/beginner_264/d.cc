#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  char s[8];
  scanf("%s", s);
  const char *p="atcoder";
  int tot=0;
  for (int i=0; i<7; i++) {
    if (s[i]==p[i]) continue;
    int j;
    for (j=0; p[i]!=s[j]; j++);
    // printf("%c %c\n", s[i], s[j]);
    for (int k=max(i,j); k>min(i,j); k--) swap(s[k], s[k-1]);
    tot+=abs(i-j);
    // printf("tot=%d\n", abs(i-j));
    // cout << s << endl;
  }
  cout << tot << endl;
  return 0;
}