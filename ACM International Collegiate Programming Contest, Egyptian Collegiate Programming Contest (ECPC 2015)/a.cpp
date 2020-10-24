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

map<int,double> ans[10];
map<string,int> order;

int fact[10];

 
void init(int lim) {
    fact[0] = 1;
    for(int i = 1; i < lim; ++i) {
        fact[i] = fact[i - 1] * i;
    }

    for(int i = 1; i <= 9; ++i){
    	string s = "";
    	for(int j = 1; j <= i; ++j){
    		s+=char('0'+j);
    	}
    	int n = fact[i];
    	ans[i][n] = 0;
    	order[s] = 1;
    	double sum = 1;
    	// cout << s _ ans[i][n] << endl;
	    for(int j = 1; next_permutation(s.begin(), s.end()); ++j){
			ans[i][n-j] = sum / n;
			sum += ans[i][n-j];
			order[s] = j+1;
	    }
    }

}

 
void solve() {

	string s, sorted;
	cin >> s;
	sorted = s;

	sort(sorted.begin(), sorted.end());

	map<char, char> mp;

	for(int i = 0; i < s.size(); ++i){
		mp[sorted[i]] = char('1'+i);
	}

	string compressed = "";

	for(int i = 0; i < s.size(); ++i){
		compressed += mp[s[i]];
	}
	// cout << compressed << endl;
	cout << ans[s.size()][order[compressed]] << endl;
}

 
int main(){
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << setprecision(9) << fixed;
	init(10);
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
