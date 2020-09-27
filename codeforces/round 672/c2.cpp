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


ull a[300300];

ull n;

ull ans;


void rev(ull i) {
	if(0 < i && i < n-1){
		if(a[i-1] < a[i] && a[i] > a[i+1]){
			ans -= a[i];
		} else if(a[i-1] > a[i] && a[i] < a[i+1]){
			ans += a[i];
		}
		return;
	}

	if(i == 0 && n > 1 && a[0] > a[1]){
		ans-=a[0];
		return;
	}
	if(i == n-1 && n > 1 && a[n-2] < a[n-1]){
		ans-=a[n-1];
		return;
	}
}

void add(ull i) {

	if(0 < i && i < n-1){
		if(a[i-1] < a[i] && a[i] > a[i+1]){
			ans += a[i];
		} else if(a[i-1] > a[i] && a[i] < a[i+1]){
			ans -= a[i];
		}
		return;
	}

	if(i == 0 && n > 1 && a[0] > a[1]){
		ans+=a[0];
		return;
	}
	if(i == n-1 && n > 1 && a[n-2] < a[n-1]){
		ans+=a[n-1];
		return;
	}
	if(i == 0 && n==1){
		ans+=a[0];
	}
}

void solve(){
	ull q;

	cin >> n >> q;



	for(ull i = 0; i < n; i++){
		cin >> a[i];
	}

	ans = 0;


	for(ull i = 0; i < n; i++){
		add(i);
	}

	cout << ans << endl;

	for(ull i = 0; i < q; i++){
		ull l,r;
		cin >> l >> r;
		l--;
		r--;
		if(l==r){
			cout << ans << endl;
			continue;
		}
		for(ull j = l-1; j <= l+1; j++){
			rev(j);
		}	
		for(ull j = max(r-1,l+2); j <= r+1; j++){
			rev(j);
		}	
		swap(a[l], a[r]);
		for(ull j = l-1; j <= l+1; j++){
			add(j);
		}	
		for(ull j = max(r-1,l+2); j <= r+1; j++){
			add(j);
		}	
		cout << ans << endl;
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
	