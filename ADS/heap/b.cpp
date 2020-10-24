#include<iostream>
#include<cmath>

using namespace std;
	

int a[400010];
int n;


void sift_up(int v){
	int parent = v/2;
	if(parent == 0) {
		cout << v << endl;
		return;
	}
	if(a[parent] < a[v]){
		swap(a[parent], a[v]);
		sift_up(parent);
	}else{
		cout << v << endl;
	}
}

void sift_down(int v){
	int ch1 = v*2, ch2 = v*2+1;
	if(ch1 > n) {
		cout << v << endl;
		return;
	}

	if(ch2 > n) {
		if(a[ch1] > a[v]){
			swap(a[ch1], a[v]);
			sift_down(ch1);
		}else{
			cout << v << endl;
		}
		return;
	}

	if(a[ch1] <= a[v] && a[ch2] <= a[v]){
		cout << v << endl;
		return;
	}

	if(a[ch1] < a[ch2]){
		swap(a[ch2], a[v]);
		sift_down(ch2);
	}else{
		swap(a[ch1], a[v]);
		sift_down(ch1);
	}
}


int main(){
	cin >> n;

	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}

	int q;
	cin >> q;

	for(int i = 0; i < q; i++){
		int v, x;
		cin >> v >> x;
		a[v] -= x;
		sift_down(v);
	}

	for(int i = 1; i <= n;i++){
		cout << a[i] << " ";
	}
};
