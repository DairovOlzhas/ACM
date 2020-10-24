#include <iostream>
 
using namespace std;
 
int count(int a[], int n){
	int cnt = 0;
	for(int i = 0; i < n; i++){
		if(a[i] > 0) cnt++;
	}
	return cnt;
}

int main(){

	int n,m;
	cin >> n >> m;
	int a[n][m];


	int ans = -1;
	int mx = -1;
	for(int i = 0; i < n ;i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
		}

		int cnt = count(a[i], m);
		if(mx == cnt){
			ans = -1;
		}else if(mx < cnt){
			ans = i+1;
			mx = cnt;
		}
	}

	if(ans == -1){
		cout << "Numbers are equal";
	}else{
		cout << ans;
	}

}
