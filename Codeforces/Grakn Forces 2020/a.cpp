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

	int a[n][3];

	for(int i = 0; i < n; i++){
		cin >> a[i][0];
	}
	for(int i = 0; i < n; i++){
		cin >> a[i][1];
	}
	for(int i = 0; i < n; i++){
		cin >> a[i][2];
	}
	int p[n];
	p[0] = a[0][0];
	for(int i = 1; i < n; i++){
		for(int j = 0; j < 3; j++){
			if(p[i-1] != a[i][j]){
				p[i] = a[i][j];
				break;
			}
		}
	}

	for(int i = 0; i < 3; i++){
		if(p[n-2] != a[n-1][i] && a[n-1][i] != p[0]){
			p[n-1] = a[n-1][i];
		}
	}

	for(int i = 0; i < n; i++){
		cout << p[i] << " ";
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
	