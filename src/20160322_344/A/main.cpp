#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)

#ifndef ONLINE_JUDGE
#define debug_int(s) printf("%s = %d\n", #s, s)
#else
#define debug_int(s)
#endif

typedef long long int_t;

const int SIZE = 100000 + 11;
int n;
string s[SIZE];

bool input() {
  if (cin >> n) {
    rep (i, n) cin >> s[i];
    return true;
  }
  return false;
}

int solve() {
  return unique(s, s+n) - s;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  while (input()) {
    cout << solve() << endl;
  }
  return 0;
}