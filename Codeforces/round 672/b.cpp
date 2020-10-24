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



void solve(){
	ull n;

	cin >> n;

	ull a[n];

	map<ull,ull> cnt;

	for(ull i = 0; i < n; i++){
		cin >> a[i];
		ull last;
		for(ull j = 0; j < 30; j++){
			if(a[i]&(1ll<<j)){
				last = j;
			}
		}
		cnt[last]++;
	}

	ull ans = 0;

	for(ull i = 0; i < 30; i++){
		ans += cnt[i]*(cnt[i]-1)/2;
	}

	cout << ans << endl;

}


int main(){
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ull q;
	cin >> q;
	// q = 1;
	for(ull i = 0; i < q; i++){
		// cout << "Case #" << i+1 << ":" << endl;
 
		solve();
		// cout << endl;
	}
 
	
 
	return 0;
}
	