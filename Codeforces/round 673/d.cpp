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

	int a[n];

	int sum = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		sum += a[i];
	}

	if(sum%n!=0){
		cout << -1 << endl;
	}else{
		int k = sum/n;
		vector<pair<int,pair<int,int> > > ans;
		for(int i = 1; i < n; i++){
			int ost = i+1-a[i]%(i+1);
			if(ost % (i+1) != 0){
				ans.push_back({1,{i+1,ost}});
				a[i] += ost;
				a[0] -= ost;
			}
			ans.push_back({i+1, {1, a[i]/(i+1)}});
			a[0] += a[i];
			a[i] = 0;
		}

		for(int i = 1; i < n; i++){
			ans.push_back({1, {i+1, k}});
			a[0] -= k;
			a[i] += k;
		}

		cout << ans.size() << endl;

		for(int i = 0; i < ans.size(); i++){
			cout << ans[i].fi _ ans[i].se.fi _ ans[i].se.se << endl;
		}
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
	