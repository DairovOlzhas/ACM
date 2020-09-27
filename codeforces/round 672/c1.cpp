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
	ull n,q;

	cin >> n >> q;

	ull a[n];


	for(ull i = 0; i < n; i++){
		cin >> a[i];
	}

	ull ans = 0;
	bool l = false;
	for(ull i = 0; i < n; i++){
		if(i -1 >= 0 && i+1 < n) {
			if(a[i-1] > a[i] && a[i] < a[i+1]) {
				ans-=a[i];
			}else if(a[i-1] < a[i] && a[i] > a[i+1]){
				ans+=a[i];
			}
		}
	}

	if(n > 1 && a[0] > a[1]){
		ans+=a[0];
	}
	if(n > 1 && a[n-2] < a[n-1]){
		ans+=a[n-1];
	}
	if(n==1){
		ans+=a[0];
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
	