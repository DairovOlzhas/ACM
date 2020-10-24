#include <bits/stdc++.h>
#include <iostream>
// #include <unordered_map>
#define vi vector <ull>
#define ii pair<ull,ull>
#define vii vector<ii>
 
#define seti set<ull>
#define mii map<ull,ull>
#define um unordered_map
#define ll long long
#define ull  long long
#define fi first
#define se second
#define pb push_back
// #define mp make_pair
#define MAX 100100
#define _ << " " <<

ull mod = 1e9+7;
 
using namespace std;


inline ull mult(ull a, ull b) {
    return 1ll * a * b % mod;
}
 
inline ull binpow(ull a, ull n) {
    ull res = 1;
    while (n) {
        if (n & 1) {
            res = mult(res, a);
        }
        a = mult(a, a);
        n >>= 1;
    }
    return res;
}
 
inline ull add(ull a, ull b) {
    if (a + b >= mod) return a + b - mod;
    else return a + b;
}
 
inline ull sub(ull a, ull b) {
    if (a - b < 0) return a - b + mod;
    else return a - b;
}
 
inline ull getinv(ull a) {
    return binpow(a, mod - 2);
}
 
inline ull divide(ull a, ull b) {
    return mult(a, getinv(b));
}

inline ull arsum(ull n){
	return divide(mult(add(1,n), n), 2);  
}

void solve(){
	ull H, W, h, w;
	cin >> H >> W >> h >> w;

	ull ans = 0;
	ans = mult(
				mult(
					mult(H, W), 
					sub(H+1,h)
					), 
				sub(W+1,w)
				);

	ans += mult(
				mult(
					h-1, 
					sub(H+1,h)
					), 
				arsum(
					sub(W+1,w)
					)
				);
	ans %= mod;
	ans += mult(
				mult(
					w-1, 
					sub(W+1,w)
					), 
				arsum(
					sub(H+1,h)
					)
				);
	ans %= mod;
	ans += mult(
				arsum(w-1),
				arsum(h-1)
				);
	ans %= mod;
	// ull cur = ans;
	ans *= ans;
	ans %= mod;


	ull a = 0;



	// ans = sub(ans, cur);

	cout << ans;
}

int main(){
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	ull q;
	// cin >> q;
	q = 1;
	for(ull i = 0; i < q; i++){
		// cout << "Case #" << i+1 << ":" << endl;
 
		solve();
		// cout << endl;
	}
 
	
 
	return 0;
}
		