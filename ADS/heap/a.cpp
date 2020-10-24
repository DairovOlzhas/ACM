#include<iostream>
#include<cmath>

using namespace std;
	

int a[100010];
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
		a[v] += x;
		sift_up(v);
	}

	for(int i = 1; i <= n;i++){
		cout << a[i] << " ";
	}
};
