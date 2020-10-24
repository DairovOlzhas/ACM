#include<iostream>

using namespace std;

int main(){


	int n, k = 0;
	cin >> n;

	int p = 1;
	while(p < n){
		k++;
		p*=2;
	}
	cout << k;
	return 0;
}