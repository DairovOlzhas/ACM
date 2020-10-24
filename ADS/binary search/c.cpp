#include<iostream>
#include<cmath>

using namespace std;
	
int main(){
	int n;
	cin >> n;
	int a[n];
	int mx = -1010;
	int ans = 1;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		if(a[i] > mx){
			mx = a[i];
			ans = i+1;
		}
	}
	cout << ans;

};