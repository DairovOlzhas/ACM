#include<iostream>
#include<cmath>

using namespace std;
	
int main(){

	int n,q;
	cin >> n >> q;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	for(int i = 0; i < q; i++){
		int x;
		cin >> x;
		bool found = false;
		int l = 0,r = n-1;
		while(l<=r){
			int m = (l+r)/2;
			if(a[m] > x){
				r = m-1;
			}else if(a[m] < x){
				l = m + 1;
			}else{
				found = true;
				break;
			}
		}

		if(found){
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
	}
};
