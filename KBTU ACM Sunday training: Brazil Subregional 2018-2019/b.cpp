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
	int n;
	cin >> n;

	bool win = false;

	int ans = 0;

	map<int,int> cnt;

	for(int i = 0; i < n; i++){
		int l,c;
		cin >> l >> c;
		if(l==c) win = true;
		else {
			ans ^= l+c-3;
		}
		cnt[l+c-3]++;
	}
	ans = 0;
	for(int i = 0; i < 300; i++){
		if(cnt[i]%2==1) ans++;
	}

	if(win || (ans > 0 && ans%2 == 1)){
		cout << "Y" ;
	}else{
		cout << "N";
	}


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
	