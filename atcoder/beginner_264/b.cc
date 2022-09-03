#include <iostream>
using namespace std;

int main()
{
  char s[][16] = {"bbbbbbbbbbbbbbb",
                "bwwwwwwwwwwwwwb",
                "bwbbbbbbbbbbbwb",
                "bwbwwwwwwwwwbwb",
                "bwbwbbbbbbbwbwb",
                "bwbwbwwwwwbwbwb",
                "bwbwbwbbbwbwbwb",
                "bwbwbwbwbwbwbwb",
                "bwbwbwbbbwbwbwb",
                "bwbwbwwwwwbwbwb",
                "bwbwbbbbbbbwbwb",
                "bwbwwwwwwwwwbwb",
                "bwbbbbbbbbbbbwb",
                "bwwwwwwwwwwwwwb",
                "bbbbbbbbbbbbbbb"};
  int r, c; cin>>r>>c;
  cout<<(s[r-1][c-1]=='b'?"black":"white")<<endl;
  return 0;
}