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


	int n,m;
	cin >> n >> m;

	int a[n], b[n], c[m], d[m]; 


	vector<pair<int,int> > vor, far;




	for(int i = 0; i < n; i++){
		cin >> a[i] >> b[i];
		vor.push_back({a[i],b[i]});
	}

	for(int i = 0; i < m; i++){
		cin >> c[i] >> d[i];
		far.push_back({c[i],d[i]});
	}

	sort(far.begin(), far.end());

	sort(vor.begin(), vor.end(), [](pair<int,int> &left, pair<int,int> &right){
		if(left.fi == left.se){
			return left.se > right.se;
		}else{
			return left.fi < right.fi;
		}

	});

	map<int,int> vv, ff;

	for(int i = 0; i < m; i++){
		ff[far[i].fi] = far[i].se;
	}	

	for(int i = 0; i < n; i++){
		vv[vor[i].fi] = vor[i].se;
	}

	map<int,int> fff;

	map<int,int>::iterator tt;

	for(auto i = ff.begin(); i != ff.end(); i++){
		if(i == ff.begin()){
			fff[0] = (*i).se+1;
		}else{
			fff[(*tt).fi+1] = (*i).se+1;
		}
		tt = i;	
	}

	fff[(*tt).fi+1] = 0;

	map<int,int> ansx, ansy;

	// int mxx = 0, mxy = 0;

	for(auto i = vv.begin(); i != vv.end(); i++){
		int xi = (*i).fi, yi = (*i).se; 
		// cout <<  "VOR:" _  xi _ yi << endl;
		// int mnx = 1e7, mny = 1e7;
		for(auto j = fff.begin(); j != fff.end(); j++ ){
			int xj = (*j).fi, yj = (*j).se; 
			ansx[xj-xi] = max(ansx[xj-xi], yj-yi);
			ansy[yj-yi] = max(ansy[yj-yi], xj-xi);
			// if(xj-xi >= 0)
			// 	mnx = min(mnx, xj-xi);
			// if(yj-yi >= 0)
			// 	mny = min(mny, yj-yi);
			// cout <<  "FAR:" _  xj _ yj _ mnx _ mny << endl;
		}
		// mxx = max(mxx, mnx);
		// mxy = max(mxy, mny);
	}

	int res = 1e9;
	for(auto i = ansx.begin(); i != ansx.end(); i++){
		if((*i).fi >= 0 && (*i).se >= 0){
			res = min(res, max((*i).fi, ansx[(*i).fi]) + max(ansy[(*i).se], (*i).se));
			// res = min(res, max((*i).se, mxy) + max((*i).fi, mxx));
		}
	}

	cout << res << endl;

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
	