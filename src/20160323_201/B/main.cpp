#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)

#ifndef ONLINE_JUDGE
#define print_int(s) printf("%s = %d\n", #s, s)
#else
#define print_int(s)
#endif

typedef long long int_t;

const int size = 100000 + 11;
int n;
int a[size];

bool input() {
  if (cin >> n) {
    rep (i, n) cin >> a[i];
    return true;
  }
  return false;
}

int solve() {
  int base = 0;
  rep (i, n) if (a[i] == i) ++base;
  if (base == n) return n;
  int to[n];
  rep (i, n) if (a[i] != i) {
    to[a[i]] = i;
  }
  rep (i, n) if (a[i] != i) {
    if (to[i] == a[i]) {
      return base + 2;
    }
  }
  return base + 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  while (input()) {
    cout << solve() << endl;
  }
  return 0;
}