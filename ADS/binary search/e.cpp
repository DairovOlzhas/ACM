#include<iostream>
#include<cmath>

using namespace std;
	
int main(){

	int n;
	cin >> n;
	int mx1 = 0, mx2 = 0;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		if(x > mx1){
			mx2 = mx1;
			mx1 = x;
		}
	}
	cout << mx2;

};
