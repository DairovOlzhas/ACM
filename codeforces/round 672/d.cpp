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

ull mod = 998244353;
 
using namespace std;



void solve(){

	ull n, k;
	cin >> n >> k;

	map<ull, map<ull,ull> > in;
	map<ull, map<ull,ull> > out;

	for(ull i = 0; i < n; i++){
		ull l,r;
		cin >> l >> r;
		in[l][0]++;
		out[r+1][1]--;
	}
	ull ans = 0;


	ull last = 0, sum = 0;

	for(auto it = cnt.begin(); it != cnt.end(); it++) {
		ull i = (*it).fi;
		ull c = (*it).se;

		ans = (ans + max(sum-k+1, 0ll)*(i-last)%mod)%mod;

		sum += c;
		last = i;
	}

	cout << ans << endl;

}


int main(){
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
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
	