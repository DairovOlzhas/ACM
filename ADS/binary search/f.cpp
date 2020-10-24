#include<iostream>
#include<cmath>

using namespace std;
	
int main(){

	int n;
	cin >> n;
	int a[n];
	int mn = 1e9, mx=-1e9;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		mn = min(mn, a[i]);
		mx = max(mx, a[i]);
	}

	for(int i = 0; i < n; i++){
		if(a[i] == mx){
			cout << mn << " ";
		}else{
			cout << a[i] << " ";
		}
	}
};
