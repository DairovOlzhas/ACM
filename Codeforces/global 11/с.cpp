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

struct CustomCompare
{
    bool operator()(const int& lhs, const int& rhs)
    {
        return lhs > rhs;
    }

};

void solve(){


	map<int, vector<pair<int, pair<int,int> > > , CustomCompare> mp;

	int r, n;
	cin >> r >> n;
	int ans = 0;
	for(int i = 0; i < n; i++){
		int t1,x1,y1;
		cin >> t1 >> x1 >> y1;
		int cur = 0;
		for(auto it = mp.begin(); it != mp.end(); it++){
			vector<pair<int, pair<int,int> > > v = (*it).se;
			bool f = false;
			for(int j = 0; j < v.size(); j++){
				int t2 = v[j].fi, x2 = v[j].se.fi, y2 = v[j].se.se;
				if(t1-t2 >= abs(x2-x1)+abs(y1-y2)){
					cur = (*it).fi + 1;
					f = true;
					break;
				}
			}
			if(f) break;
		}
		if(cur!=0){
			mp[cur].push_back({t1,{x1, y1}});
		}else if(t1 >= abs(x1-1)+abs(y1-1)){
			mp[1].push_back({t1,{x1, y1}});
		}
	}

	// for(auto it = mp.begin(); it != mp.end(); it++){
	// 	cout << (*it).fi << " ";
	// }
	// cout << endl;

	if(mp.size())
		cout << (*mp.begin()).fi << endl;
	else
		cout << 0 << endl;
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
	