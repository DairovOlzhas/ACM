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

int n,m,px,py, x,y, sz;
string d[11][11];
	
void make_step(string d){

	if(d == "LD"){
		if(px-1 == x && py == y){
			cout << "L" << endl;
			px--;
		}else{
			py++;
			cout << "D" << endl;
		}
		return;
	}
	cout << d << endl;
	if(d == "R") px++;
	else if(d == "L") px--;
	else if(d == "U") py--;
	else py++;
}

void construct_steps(){
	for(int x = 1; x <= m; x++){ 	// up down zig-zags
		for(int y = 1; y <=n; y++){
			if(x%2) d[x][y] = "U";
			else d[x][y] = "D";
		}
	}

	for(int x = 1; x <= m; x++){ 
		if(x < m){  // connecting up down zig-zags
			if(x%2){
				d[x][1] = "R";
			}else{
				d[x][n-1] = "R";
			}
		}
		if(x!=1){
			d[x][n] = "L"; // bottom path to position (1,n)
		}
	}

	if(m%2){ // make zig-zags for last two columns
		for(int y = 1; y < n; y++){
			if(y%2){
				d[m-1][y] = "R";
				d[m][y] = "D";
			}else{
				d[m-1][y] = "D";
				d[m][y] = "L";
			}
		}
		if(n%2){ // vilka
			d[m][n-1] = "LD";
		}
	}
}

void solve(){
	sz = 1;
	cin >> n >> m; 
	construct_steps();
	// for(int i = 1; i <= n; i++){
	// 	for(int j = 1; j <= m; j++){
	// 		cout << d[j][i] << " ";
	// 	}
	// 	cout << endl;
	// }
	
	cin >> py >> px >> y >> x;

	while(true) {

		make_step(d[px][py]);

		string res;
		cin >> res;
		if(res == "new"){
			sz++;
			cin >> y >> x;
		}else if(res == "fail" || res == "win"){
			exit(0);
		}
	}

}

int main(){
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
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
		