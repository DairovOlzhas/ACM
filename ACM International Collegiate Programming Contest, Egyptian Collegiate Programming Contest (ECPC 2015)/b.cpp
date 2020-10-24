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


 
void solve() {


	int n,m;
	cin >> n >> m;

	map<int, set<char> > ans;
	set<char> tmp;
	tmp.insert('A');
	tmp.insert('B');
	tmp.insert('C');
	tmp.insert('D');
	for(int i = 0; i < n; i++){
		ans[i] = tmp;
	}

	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			char q,a;
			cin >> q >> a;
			if(a == 'T'){
				set<char> tmp;
				tmp.insert(q);
				ans[j] = tmp;
			}else{
				ans[j].erase(q);
			}
		}
	}
	vector<char> anss;
	for(int i = 0; i < n; i++){
		if(ans[i].size() == 1){
			anss.push_back(*ans[i].begin());
		}else{
			anss.push_back('?');
		}
	}

	for(int i = 0; i < anss.size(); i++){
		cout << anss[i];
		if(i != anss.size()-1){
			cout << " ";
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
