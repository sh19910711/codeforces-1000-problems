#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)

#ifndef ONLINE_JUDGE
#define debug_int(s) printf("%s = %d\n", #s, s)
#else
#define debug_int(s)
#endif

typedef long long int_t;

int a, b, c;

bool input() {
  if (cin >> a >> b >> c) {
    return true;
  }
  return false;
}

int res[3];

bool find() {
  const int d[3] = {a, b, c};
  rep (o, 3) {
    int i0 = o;
    int i1 = (i0+1)%3;
    int i2 = (i1+1)%3;
    rep (x, d[i0]) {
      if (d[i0] + d[i1] - 2 * x == d[i2]) {
        res[i0] = x;
        if (b - x < 0) continue;
        res[i1] = b - x;
        if (a - x < 0) continue; 
        res[i2] = a - x;
        if (res[i0] + res[i1] == d[i1] && res[i1] + res[i2] == d[i2] && res[i2] + res[i0] == d[i0]) {
          debug_int(res[i0]+res[i1]);
          debug_int(res[i1]+res[i2]);
          debug_int(res[i2]+res[i0]);
          return true;
        }
      }
    }
  }
  return false;
}

void solve() {
  if (find()) {
    cout << res[0] << " " << res[1] << " " << res[2] << endl;
  } else {
    cout << "Impossible" << endl;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  while (input()) {
    solve();
  }
  return 0;
}