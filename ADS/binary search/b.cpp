#include<iostream>
#include<cmath>

using namespace std;
	
int main(){
	int n;
	cin >> n;
	int a[n];
	int mx = -1010;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		mx = max(mx, a[i]);
	}
	cout << mx;

};
