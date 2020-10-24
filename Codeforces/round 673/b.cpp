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

	int n, t;
	cin >> n >> t;

	int a[n];
	map<int,bool> exist;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		exist[a[i]] = true;
	}
	int ans[n];
	int cnt = 0;
	for(int i = 0; i < n; i++){
		if(a[i]*2 == t){
			ans[i] = cnt++%2;
		}else if(exist[t-a[i]] && a[i]*2 > t){
			ans[i] = 1;
		}else{
			ans[i] = 0;
		}
	}

	for(int i = 0; i < n; i++){
		cout << ans[i] << " ";
	}
	cout << endl;

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
	