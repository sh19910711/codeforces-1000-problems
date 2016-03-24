#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)

#ifndef ONLINE_JUDGE
#define print_int(s) printf("%s = %d\n", #s, s)
#else
#define print_int(s)
#endif

typedef long long int_t;

const int size = 100001;
int_t n;
int_t a[size];


bool input() {
  if (cin >> n) {
    rep (i, n) cin >> a[i];
    return true;
  }
  return false;
}

bool solve() {
  int cnt25 = 0;
  int cnt50 = 0;
  rep (i, n) {
    if (a[i] == 25) {
      cnt25 += 1;
    } else if (a[i] == 50) {
      if (cnt25 == 0) return false;
      cnt25 -= 1;
      cnt50 += 1;
    } else if (a[i] == 100) {
      if (cnt25 >= 1 && cnt50 >= 1) {
        cnt25 -= 1;
        cnt50 -= 1;
      } else if (cnt25 >= 3) {
        cnt25 -= 3;
      } else {
        return false;
      }
    }
  }
  return true;
}

void output(const bool& res) {
  cout << (res ? "YES" : "NO") << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  while (input()) {
    output(solve());
  }
  return 0;
}