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
	map<int,int> last;
	map<int,int> mx_dist;
	for(int i = 0; i < n; i++){
		cin >> a[i];

		if(mx_dist[a[i]] == 0){
			mx_dist[a[i]] = max(mx_dist[a[i]], i-last[a[i]]+1);
		}else{
			mx_dist[a[i]] = max(mx_dist[a[i]], i-last[a[i]]);
		}

		last[a[i]] = i;
	}

	for(int i = 0; i < n; i++){
		mx_dist[a[i]] = max(mx_dist[a[i]], (n-1)-last[a[i]]+1);
	}
	map<int,int> dist;

	for(auto it = mx_dist.begin(); it != mx_dist.end(); it++){
		// cout << (*it).fi _ (*it).se << endl;
		dist[(*it).se] = (dist[(*it).se]==0)?(*it).fi:min(dist[(*it).se], (*it).fi);
	}
	int mn = n+1;

	for(auto it = dist.begin(); it != dist.end(); it++){
		// cout << (*it).fi _ (*it).se << endl;
	}

	for(int i = 1; i <= n; i++){
		if(dist[i] == 0){
			if(mn == n+1){
				cout << -1 << " ";
			}else{
				cout << mn << " ";
			}
		}else{
			mn = min(dist[i], mn);
			cout << mn << " ";
		}
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
	