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

bool ans[1010], cur[1010];

void solve(){
	int n,m;
	cin >> n >> m;
	int l;
	cin >> l;
	int x[l];
	for(int i = 0; i < l; i++){
		cin >> x[i];
		ans[x[i]] = true;
	}

	vector<int> b[n];
	for(int i = 0; i < n; i++){
		int k;
		cin >> k;ф
		for(int j = 0; j < k; j++) {
			int y;
			cin >> y;
			b[i].push_back(y);
		}
	}

	for(int i = 0; i < 2*n; i++){
		bool found = true;
		for(int j = 1; j <= m; j++){
			if(cur[j]!=ans[j]){
				found = false;
				break;
			}
		}
		if(found){
			cout << i;
			return;
		}
		for(int j = 0; j < b[i%n].size(); j++){
			cur[b[i%n][j]] = !cur[b[i%n][j]];
		}
	}
	cout << -1;
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
	