#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)

#ifndef ONLINE_JUDGE
#define debug_int(s) printf("%s = %d\n", #s, s)
#else
#define debug_int(s)
#endif

typedef long long int_t;

const int size = 100;
int n;
int a[size];

bool input() {
  if (cin >> n) {
    rep (i, n) cin >> a[i];
    return true;
  }
  return false;
}

int b[size];

void solve() {
  copy(a, a+n, b);
  sort(b, b+n, greater<int>());
  rep (i, n/2) {
    swap(b[i+1], b[n-i-2]);
  }
  if (n%2 == 0) {
    swap(b[n/2-1], b[n/2]);
  }
}

void output() {
  rep (i, n) cout << b[i] << " ";
  cout << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  while (input()) {
    solve(); output();
  }
  return 0;
}