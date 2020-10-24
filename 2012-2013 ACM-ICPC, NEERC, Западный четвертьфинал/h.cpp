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




int to_roman(int n){
	int res = 0;
	map<int,int> sz;

	sz[0] = 0;
	sz[1] = 1;
	sz[2] = 2;
	sz[3] = 3;
	sz[4] = 2;
	sz[5] = 1;
	sz[6] = 2;
	sz[7] = 3;
	sz[8] = 4;
	sz[9] = 2;

	while(n != 0){
		res+=sz[n%10];
		n/=10;
	}

	return res;
}


void solve(){
	string s;
	cin >> s;

	string from = s.substr(0, s.find('-'));
	string to = s.substr(s.find('-')+1, s.size());

	// cout << from _ to << endl;
	int f = 0, t = 0;
	for(int i = 0; from[i] != 'B' && from[i] != 'A'; i++){
		f*=10;
		f+=from[i]-'0';
	}
	if(from[from.size()-2] == 'B'){
		f = -f;
	}

	for(int i = 0; to[i] != 'B' && to[i] != 'A'; i++){
		t*=10;
		t+=to[i]-'0';
	}
	if(to[to.size()-2] == 'B'){
		t = -t;
	}


	int ans = 0;
	// int n = t-f;
	// cout << n << endl;

	if(f < 0) f += 754;
	else f += 753;
	if(t < 0) t += 754;
	else t += 753;

	for(int i = f; i <= t; i++){
		ans = max(ans, to_roman(i));
	}

	cout << ans;
}

  
 
int main(){
	freopen("roman.in", "r", stdin);
	freopen("roman.out", "w", stdout);
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
	