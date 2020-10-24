#include<iostream>
#include<cmath>

using namespace std;
	
int main(){

	int n,m;
	cin >> n >> m;
	int a[n][m];
	int mx[m], mn[n];
	for(int i = 0; i < n; i++){
		mn[i] = 10000;
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
			mn[i] = min(mn[i], a[i][j]);
		}
	}	

	for(int j = 0; j < m; j++){
		mx[j] = -10000;
		for(int i = 0; i < n; i++){
			mx[j] = max(mx[j], a[i][j]);
		}
	}	

	int cnt = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j] == mn[i] && a[i][j] == mx[j])cnt++;
		}
	}

	cout << cnt;

};
