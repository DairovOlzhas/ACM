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

int a[100], b[100], n;
vector<int> ops;


bool sorted(){
	for(int i = 0; i < n; i++){
		if(a[i]!=b[i])return false;
	}
	return true;
}

void make_ops(){
	vector<vector<int> > rev;
	vector<int> cur;
	int ind = 0;
	for(int i = 0; i < ops.size(); i++){
		cur.clear();
		for(int j = 0; j < ops[i]; j++){
			cur.push_back(a[ind+j]);
		}
		rev.push_back(cur);
		ind+=ops[i];
	}	
	reverse(rev.begin(), rev.end());
	ind = 0;
	for(int i = 0; i < rev.size(); i++){
		for(int j = 0; j < rev[i].size(); j++){
			a[ind+j] = rev[i][j];
		}
		ind += rev[i].size();
	}
	for(int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	cout << endl << endl;
}


void solve(){

	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> a[i];
		b[i] = a[i];
	}

	sort(b, b+n);
	map<pair<int,int>, bool> exist;
	
	for(int i = 1; i < n; i++){
		exist[{b[i-1], b[i]}] = true;
	}

	vector<vector<int> > ans;

	while(!sorted()){
		ops.clear();

		int cnt = 1;
		for(int i = 1; i < n; i++){
			if(exist[{a[i-1], a[i]}]){
				cnt++;
			}else{
				ops.push_back(cnt);
				cnt = 1;
			}
		}
		ops.push_back(cnt);
		ans.push_back(ops);

		for(int i = 0; i < ops.size(); i++){
			cout << ops[i] << " ";
		}
		cout << endl;

		make_ops();
	}


	cout << ans.size() << endl;
	for(auto op: ans){
		cout << op.size() << " ";
		for(auto j: op){
			cout << j << " ";
		}
		cout << endl;
	}
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
	