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
    bool operator()(const pair<int,int>& lhs, const pair<int,int>& rhs)
    {
        return lhs.fi >= rhs.fi;
    }

};


bool a[100100];
int n; 

int get(int i){
	if(i-1 > 0 && i+1 < n) {
		if(a[i-1] && a[i+1]) return 3;
		if(!a[i-1] && !a[i+1]) return 1;
		return 2; 
	}
	if(i - 1 > 0 && a[i-1]){
		return 2;
	}
	if(i+1 < n && a[i+1]){
		return 2;
	}
	return 1;
}

void solve(){
	int k;
	cin >> n >> k;
	string s;
	cin >> s;


	for(int i = 0; i < n; i++){
		a[i] = (s[i] == 'W');
	}

	set<pair<int,int>,  CustomCompare> ss;

	for(int i = 0; i < n; i++){
		if(!a[i]){
			ss.insert({get(i), i});
		}
	}

	for(int kk = 0; kk < k; kk++){
		if(ss.size() == 0) break;
		auto it = ss.begin();
		pair<int,int> mx = *it;
		a[mx.se] = true;
		int i = mx.se;
		ss.erase(it);

		for(int j = 1; j <= 3; j++){
			auto it = ss.find({j, i-1});
			if(it != ss.end()){
				ss.erase(it);
				ss.insert({get(i-1),i-1});
				break;
			}
		}
		for(int j = 1; j <= 3; j++){
			auto it = ss.find({j, i+1});
			if(it != ss.end()){
				ss.erase(it);
				ss.insert({get(i+1),i+1});
				break;
			}
		}
	}

	int ans = 0;
	int last = 0;
	for(int i = 0; i < n; i++){
		if(a[i]) {
			ans += 1 + last;
			last = 1;
		}else{
			last = 0;
		}
	}

	for(int i = 0; i < n; i++){
		if(a[i]) cout << "W";
		else cout << "L";
	}
	cout << endl;

	cout << ans << endl;
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
	