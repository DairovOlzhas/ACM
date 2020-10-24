#include <fstream>
#include <numeric>
#include <unordered_set>
#include <sstream>
#include <cassert>
#include <tuple>
#include <iomanip>
#include <random>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <chrono>
#include <stack>
#include <string>
#include <bitset>
#include <unordered_map>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
 
#define rep(i,x,y) for(int i = x; i <= y; ++i)
#define repr(i,x,y) for(int i = x; i >= y; --i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x.size())
#define pb push_back
#define endl "\n" // interactive problem
#define ll long long
#define int long long
 
using namespace std;
 
const int N = (int)(1e6) + 322;
const int inf = (int)(1e9) + 322;
const long long INF = (long long)(1e18) + 322;
const int mod = (int)(1e9) + 7;
 
 
int fact[N], inv[N];
 
inline int mult(int a, int b) {
    return 1ll * a * b % mod;
}
 
inline int binpow(int a, int n) {
    int res = 1;
    while (n) {
        if (n & 1) {
            res = mult(res, a);
        }
        a = mult(a, a);
        n >>= 1;
    }
    return res;
}
 
inline int add(int a, int b) {
    if (a + b >= mod) return a + b - mod;
    else return a + b;
}
 
inline int sub(int a, int b) {
    if (a - b < 0) return a - b + mod;
    else return a - b;
}
 
inline int getinv(int a) {
    return binpow(a, mod - 2);
}
 
inline int divide(int a, int b) {
    return mult(a, getinv(b));
}
 
inline int C(int n, int k) {
    if (k == 0) return 1;
    if (n < k) return 0;
    return mult(fact[n], mult(inv[k], inv[n - k]));
}
 
void init(int lim) {
    fact[0] = 1;
    inv[0] = 1;
    for(int i = 1; i < lim; ++i) {
        fact[i] = fact[i - 1] * i % mod;
        inv[i] = binpow(fact[i], mod - 2);
    }
}
 
void solve() {
    int rest = 0;
    int x; string s; cin >> s;
    int n = fact[sz(s)];
    // do {
    //     rest++;
    // }while (next_permutation(all(s)));
    // rest--;

    map<char,int> used;

    int less = 1;
    for(int i = 0; i < s.size(); i++){

        int cnt = 0;

        for(int j = 0; j < s.size(); j++){
            if(!used[s[j]] && s[j] < s[i])cnt++;
        }

        less = (less + (cnt * fact[s.size()-i-1])%mod ) %mod;

        used[s[i]] = true;
    }
    rest = (fact[s.size()] - less + mod)%mod;
    // cout << n << ' ' << rest << endl;
    double ans = 0;
    if (rest == 0) {
        cout << ans << endl;
        return;
    }
    double pw = 1;
    rep(i, 1, rest) {
        pw /= n;
        ans += C(rest - 1, i - 1) * pw;
    }
    cout << ans << endl;
}
 
signed main () {
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(9) << fixed;
    int t = 1; cin >> t;
    init(N - 1);
    for(int tt = 1; tt <= t; ++tt) {
        solve();
    }
    return 0;
}