#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define print_int(s) printf("%s = %d\n", #s, s)
#else
#define print_int(s)
#endif

#define rep(i, n) for (int i = 0; i < n; ++i)

typedef long long int_t;

const int size = 100;
int n;
int x[size];

bool input() {
  if (cin>>n) {
    rep (i, n) cin >> x[i];
    return true;
  }
  return false;
}

int gcd(int a, int b) {
  if (!b) return a;
  return gcd(b, a % b);
}

bool solve() {
  int d = x[0];
  rep (i, n) d = gcd(d, x[i]);
  print_int(*max_element(x, x+n));
  print_int(d);
  return (*max_element(x, x+n) / d - n) % 2;
}

void output(bool ret) {
  cout << (ret ? "Alice" : "Bob") << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  while (input()) {
    output(solve());
  }
  return 0;
}