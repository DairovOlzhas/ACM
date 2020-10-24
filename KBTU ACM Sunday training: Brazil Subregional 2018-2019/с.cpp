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


ull get_intersections(vector<pair<ull,ull> > v){


	

	
	return res;
}

void solve(){

	ull x,y,h,v;
	cin >> x >> y >> h >> v;


	vector<pair<ull,ull> > vv;
	vector<pair<ull,ull> > hh;
	for(int i = 0; i < h; i++){
		ull y1,y2;
		cin >> y1 >> y2;
		hh.push_back({y1,y2});		
	}




	for(int i = 0; i < v; i++){
		ull x1,x2;
		cin >> x1 >> x2;
		vv.push_back({x1,x2});
	}

	ull ans = (h+1)*(v+1) + get_intersections(vv) + get_intersections(hh);


	cout << ans;
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
	