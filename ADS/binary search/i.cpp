#include<iostream>

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

		int lb = -1, ub = -1;


		int l = 0,r = n-1;
		while(l<=r){
			int m = (l+r)/2;
			if(a[m] > x){
				r = m-1;
			}else if(a[m] < x){
				l = m + 1;
			}else{
				lb = m;
				r = m-1;
			}
		}

		l = 0,r = n-1;
		while(l<=r){
			int m = (l+r)/2;
			if(a[m] > x){
				r = m-1;
			}else if(a[m] < x){
				l = m + 1;
			}else{
				ub = m;
				l = m+1;
			}
		}

		if(lb == -1 || ub == -1){
			cout << 0 << endl;
		}else{
			cout << lb+1 << " " << ub+1 << endl;
		}

	}
};
