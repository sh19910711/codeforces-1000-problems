#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define print_int(s) printf("%s = %d\n", #s, s)
#else
#define print_int(s)
#endif

#define rep(i, n) for (int i = 0; i < n; ++i)

typedef long long int_t;

int a, b, c;

bool input() {
  if (cin>>a>>b>>c) {
    return true;
  }
  return false;
}

int res[3];

bool solve() {
  rep (x, a+1) {
    int y = b - x;
    int z = c - y;
    if (x < 0 || y < 0 || z < 0) continue;
    if (x + z == a) {
      print_int(x);
      print_int(y);
      print_int(z);
      res[0] = x;
      res[1] = y;
      res[2] = z;
      return true;
    }
  }
  return false;
}

void output(bool ret) {
  if (ret) {
    rep (i, 3) cout << res[i] << " ";
    cout << endl;
  } else {
    cout << "Impossible" << endl;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  while (input()) {
    output(solve());
  }
  return 0;
}