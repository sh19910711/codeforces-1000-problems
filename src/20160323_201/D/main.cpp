#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)

#ifndef ONLINE_JUDGE
#define print_int(s) printf("%s = %d\n", #s, s)
#define print_string(s) printf("%s = %s\n", #s, s.c_str())
#else
#define print_int(s)
#define print_string(s)
#endif

typedef long long int_t;

const int size = 100 + 11;
string s1;
string s2;
string v;

bool input() {
  if (cin >> s1 >> s2 >> v) {
    return true;
  }
  return false;
}

void solve() {
  int n = max(s1.size(), s2.size());
  int dp1[size][size];
  string dp2[size][size];
  rep (i, n) fill(dp1[i], dp1[i]+n, 0);
  rep (i, n) fill(dp2[i], dp2[i]+n, "");
  rep (i, n) rep (j, n) {
    auto& next1 = dp1[i+1][j+1];
    auto& next2 = dp2[i+1][j+1];
    if (s1[i] == s2[j]) {
      next1 = dp1[i][j] + 1;
      next2 = dp2[i][j] + s1[i];
    } else {
      if (next1 < dp1[i+1][j]) {
        next1 = dp1[i+1][j];
        next2 = dp2[i+1][j];
      } else if (next1 < dp1[i][j+1]) {
        next1 = dp1[i][j+1];
        next2 = dp2[i][j+1];
      }
    }
  }
  print_int(dp1[n][n]);
  print_string(dp2[n][n]);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  while (input()) {
    solve();
  }
  return 0;
}