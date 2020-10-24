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

int n,L;

vector<int> a;


double finddist2(double t){
	double l = L;

	double res = 0;
	double speed = 1;


	for(int i = 1; i < a.size(); i++){
		if((a[i]-a[i-1]+0.0)/speed < t){
			res += (a[i]-a[i-1]+0.0);
			t-=(a[i]-a[i-1]+0.0)/speed;
			speed++;
		}else{
			res += speed*t;
			break;
		}
	}

	return res;
}


double finddist1(double t){
	double l = L;

	double res = 0;
	double speed = 1;


	for(int i = a.size()-2; i >= 0; i--){
		if((a[i+1]-a[i]+0.0)/speed < t){
			res += (a[i+1]-a[i]+0.0);
			t-=(a[i+1]-a[i]+0.0)/speed;
			speed++;
		}else{
			res += speed*t;
			break;
		}
	}

	return res;
}

void solve(){


	cin >> n >> L;

	a.clear();
	a.push_back(0);
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		a.push_back(x);
	}
	a.push_back(L);



	double l = 0,r = 1e9;

	double lastm = 0;
	while(l<r){
		double m = (l+r)/2;
		// cout << l _ r << endl;
		double dist = finddist1(m) + finddist2(m);
		if(abs(lastm-m) < 1e-6){
			break;
		}
		if(dist < L){
			l = m+1e-6;
		}else{
			r = m;
		}
		lastm = m;
	}

	cout << setprecision(12);
	cout << lastm << endl;

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
	