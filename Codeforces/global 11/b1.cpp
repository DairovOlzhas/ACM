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
	int ans = 0;
	int last = 0;
	int cntl = 0;
	for(int i = 0; i < n; i++){
		if(a[i]) {
			ans += 1 + last;
			last = 1;
		}else{
			last = 0;
			cntl++;
		}

	}
	k = min(k, cntl);
	if(k == 0){
		cout << ans << endl;
		return;
	}
	vector<int> v;
	int cnt = 0;
	bool w = false;
	for(int i = 0; i < n; i++){
		if(a[i]) w = true;
		if(w){
			if(!a[i]){
				cnt++;
			}else if(cnt){
				v.push_back(cnt);
				cnt = 0;
			}
		}
	}

	// for(int i = 0; i < v.size(); i++){
	// 	cout << v[i] << " ";
	// }
	// cout << endl;

	if(!w){
		cout << (k-1)*2+1 << endl;
		return;
	}

	sort(v.begin(), v.end());

	for(int i = 0; i < v.size(); i++){
		if(v[i] <= k){
			ans += v[i]*2+1;
			k-=v[i];
		}else{
			break;
		}
	}

 	ans += 2*k;

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
	