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

vector<ull> childs[100100];
map<ull,ull> p, c;

void bfs(ull v){
	ull mn = 1e16;

	for(int i = 0; i < childs[v].size(); i++){
		int to = childs[v][i];
		mn = min(mn, c[to]);
	}

	for(int i = 0; i < childs[v].size(); i++){
		int to = childs[v][i];
		c[to] = 2*c[to] - mn;
	}

	for(int i = 0; i < childs[v].size(); i++){
		int to = childs[v][i];
		bfs(to);
	}
}

ull get(ull v){
	if(v == 1) return 0;
	return c[v] + get(p[v]);
}



void solve(){

	ull n;
	cin >> n;
	p.clear();
	c.clear();
	for(ull i = 0; i < n+10; i++){
		childs[i].clear();
	}

	for(ull u = 2; u <= n; u++){
		ull v,w;
		cin >> v >> w;
		childs[v].push_back(u);
		p[u] = v;
		c[u] = w;
	}


	bfs(1);

	vector<ull> v;

	for(ull i = 1; i <= n; i++){
		if(childs[i].size() == 0){
			v.push_back(get(i));
		}
	}

	sort(v.begin(), v.end());

	ull q;
	cin >> q;

	for(ull i = 0 ; i < q; i++){
		ull t;
		cin >> t;

		ull l = 0,r = v.size()-1;
		ull ans = 0;
		while(l <= r){
			ull m = (l+r)/2;
			if(v[m] <= t){
				ans = max(ans, m+1);
				l = m + 1;
			}else{
				r = m - 1;
			}
		}

		cout << ans << endl;
	}


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
		