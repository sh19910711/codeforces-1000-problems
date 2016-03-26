#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define print_int(s) printf("%s = %d\n", #s, s)
#else
#define print_int(s)
#endif

#define rep(i, n) for (int i = 0; i < n; ++i)

typedef long long int_t;

const int size = 11;
const int v_max = 1000000+1;
int v;
int a[size];

bool input() {
  if (cin>>v) {
    rep (i, 9) cin >> a[i+1];
    return true;
  }
  return false;
}

int res[v_max];
int n;
void solve() {
  n = 0;
  int mi = *min_element(a+1, a+9+1);
  if (v < mi) return;
  n = v / mi;
  for (int x = 9; x >= 1; --x) {
    if (a[x] == mi) {
      rep (i, n) res[i] = x;
      break;
    }
  }
  v -= n * mi;
  print_int(v);
  print_int(mi);

  int p = 0;
  while (v > 0 && p < n) {
    for (int x = 9; x >= 1; --x) {
      if (a[x] <= v + mi) {
        res[p++] = x;
        v -= a[x];
        v += mi;
        break;
      }
    }
  }
}

void output() {
  if (n == 0) {
    cout << -1;
  } else {
    rep (i, n) cout << res[i];
  }
  cout << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  while (input()) {
    solve();
    output();
  }
  return 0;
}