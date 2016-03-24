#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)

#ifndef ONLINE_JUDGE
#define print_int(s) printf("%s = %d\n", #s, s)
#else
#define print_int(s)
#endif

typedef long long int_t;

int v;
int a[10];

bool input() {
  if (cin >> v) {
    rep (i, 9) cin >> a[i];
    return true;
  }
  return false;
}

void solve() {
  typedef tuple<int, int> node_t;
  typedef vector<node_t> vector_t;
  vector_t vec;
  rep (i, 9) {
    vec.emplace_back(v/a[i], i);
  }
  sort(begin(vec), end(vec), greater<node_t>());
  const auto& best = *begin(vec);
  auto len = get<0>(best);
  auto x = get<1>(best);
  int cand = x;
  rep (i, 9) {
    if (i < x) continue;
    if ((v % a[x]) >= a[i]) {
      cand = i;
    }
  }
  if (len == 0) {
    cout << -1 << endl;
    return;
  }
  cout << (cand+1);
  rep (i, len-1) cout << (x+1);
  cout << endl;
  print_int(cand);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  while (input()) {
    solve();
  }
  return 0;
}