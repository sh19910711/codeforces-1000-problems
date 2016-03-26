#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define print_int(s) printf("%s = %d\n", #s, s)
#else
#define print_int(s)
#endif

#define rep(i, n) for (int i = 0; i < n; ++i)

typedef long long int_t;

int_t a, b;

bool input() {
  if (cin>>a>>b) {
    return true;
  }
  return false;
}

int_t solve() {
  int_t res = 1;
  while (a > 1 && b > 1) {
    if (a > b) swap(a, b);
    res += b / a;
    b %= a;
  }
  if (a > b) swap(a, b);
  res += b - 1;
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  while (input()) {
    cout<<solve()<<endl;
  }
  return 0;
}