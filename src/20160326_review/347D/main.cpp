#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define print_int(s) printf("%s = %d\n", #s, s)
#else
#define print_int(s)
#endif

#define rep(i, n) for (int i = 0; i < n; ++i)

typedef long long int_t;

string sa;
string sb;
string sv;

bool input() {
  if (cin>>sa>>sb>>sv) {
    return true;
  }
  return false;
}

struct prev_t {
  int i, j, k;
  prev_t() {
    i = j = k = -1;
  }
  prev_t(int i, int j, int k): i(i), j(j), k(k) {}
  bool operator==(const prev_t& that) {
    return i == that.i && j == that.j && k == that.k;
  }
};

const int size= 100+2;

int n, m, l;
int dp[size][size][size];
prev_t prv[size][size][size];
int automaton[size][256];
int prefix[size];

void get_automaton() {
  rep (i, size) prefix[i] = 0;
  rep (i, size) rep (j, 256) automaton[i][j] = 0;
  for (int i=1; i<l; ++i) {
    int j = prefix[i-1];
    while (j && sv[i] != sv[j]) j = prefix[j-1];
    if (sv[i] == sv[j]) ++j;
    prefix[i] = j;
  }
  for (int i=0; i<l; ++i) {
    for (char c='A'; c<='Z'; ++c) {
      if (i && c != sv[i]) {
        automaton[i][c] = automaton[prefix[i-1]][c];
      } else {
        automaton[i][c] = i+(c==sv[i]);
      }
    }
  }
}

void init_length() {
  n = sa.size();
  m = sb.size();
  l = sv.size();
}

void init_prev() {
  rep (i, size) rep (j, size) rep (k, size) {
    prv[i][j][k] = prev_t();
  }
}

void init_dp() {
  rep (i, size) rep (j, size) rep (k, size) {
    dp[i][j][k] = 0;
  }
}

string solve() {
  init_dp();
  init_prev();
  init_length();
  get_automaton();
  
  dp[0][0][0] = 0;
  int res = 0;
  prev_t none(-1, -1, -1);
  prev_t last_node = none;
  
  rep (i, n) rep (j, m) rep (k, l) {
    auto& cur = dp[i][j][k];
    bool same = (sa[i] == sb[j]);
    int next = automaton[k][sa[i]];
    if ((same && next < l) && (dp[i+1][j+1][next] < cur+1)) {
      dp[i+1][j+1][next] = cur+1;
      prv[i+1][j+1][next] = prev_t(i, j, k);
    }
    if (cur > dp[i+1][j][k]) {
      dp[i+1][j][k] = cur;
      prv[i+1][j][k] = prv[i][j][k];
    }
    if (cur > dp[i][j+1][k]) {
      dp[i][j+1][k] = cur;
      prv[i][j+1][k] = prv[i][j][k];
    }
  }
  
  rep (i, n+1) rep (j, m+1) rep (k, l) if (res < dp[i][j][k]) {
    res = dp[i][j][k];
    last_node = prv[i][j][k];
  }
  
  string out;
  for(;;) {
    if (last_node == none) break;
    out += sa[last_node.i];
    last_node = prv[last_node.i][last_node.j][last_node.k];
    if (last_node == none) break;
  }
  
  reverse(begin(out), end(out));
  
  if (out == "") return "0";
  return out;
}

void output(const string& ret) {
  cout << ret << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  while (input()) {
    output(solve());
  }
  return 0;
}