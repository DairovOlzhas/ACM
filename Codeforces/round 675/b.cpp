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
	ull n,m;
	cin >> n>> m;	
	ull a[n][m];

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
		}
	}
	ull ans = 0;
	for(int i = 0; i < n/2; i++){
		for(int j = 0; j < m/2; j++){
			ull sum = a[i][j] + a[n-1-i][j] + a[n-1-i][m-1-j] + a[i][m-1-j];
			ull avg = sum / 4;
			ull mn = 1e9;
			mn = min(mn, abs(avg-a[i][j]) + abs(avg-a[n-1-i][j]) + abs(avg-a[n-1-i][m-1-j]) + abs(avg-a[i][m-1-j]));
			avg--;
			mn = min(mn, abs(avg-a[i][j]) + abs(avg-a[n-1-i][j]) + abs(avg-a[n-1-i][m-1-j]) + abs(avg-a[i][m-1-j]));
			avg+=2;
			mn = min(mn, abs(avg-a[i][j]) + abs(avg-a[n-1-i][j]) + abs(avg-a[n-1-i][m-1-j]) + abs(avg-a[i][m-1-j]));
			ans += mn;
		}
	}	

	if(n%2==1){
		for(int i = 0; i < m/2; i++){
			ull avg = (a[n/2][i] + a[n/2][m-1-i])/2;
			ans += abs(avg-a[n/2][i]) + abs(avg-a[n/2][m-1-i]);
		}
	}
	if(m%2==1){
		for(int i = 0; i < n/2; i++){
			ull avg = (a[i][m/2] + a[n-1-i][m/2])/2;
			ans += abs(avg-a[i][m/2]) + abs(avg-a[n-1-i][m/2]);
		}
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
	