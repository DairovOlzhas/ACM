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


int n, x[1010], y[1010];
double dp[1010];

 
double get_koef(int i, int j){
	if(y[i] - y[j] == 0) return 0;
	return (y[i] - y[j]+0.0)/(x[i] - x[j]);
}

double get_dist(int j, int i){
	return sqrt((y[i] - y[j])*(y[i] - y[j]) + (x[i] - x[j])*(x[i] - x[j]));
}

void solve() {

	cin >> n;	
	for(int i = 0; i < n; i++){
		dp[i] = 1e12;
		cin >> x[i] >> y[i];
	}
	dp[0] = 0;
	for(int i = 1; i < n; i++){
		double mn = 1e12;
		// cout << mn << endl;
		for(int j = i-1; j >= 0; j--){
			double koef = get_koef(i,j);

			// cout << i _ j _ koef << endl;

			if(koef <= mn){
				mn = koef;
				dp[i] = min(dp[i], dp[j] + get_dist(i,j));
				if(j > 1){
					dp[i] = min(dp[i], dp[j-1] + get_dist(i,j));
				}
			}
		}
	}

	cout << dp[n-1] << endl;
}
 
int main(){
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cout << setprecision(6) << fixed;

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
