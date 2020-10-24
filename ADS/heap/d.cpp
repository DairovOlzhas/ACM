#include<iostream>
#include<cmath>

using namespace std;
	

int a[400010];
int n, s;


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
	if(ch1 > s) {
		cout << v << " ";
		return;
	}

	if(ch2 > s) {
		if(a[ch1] > a[v]){
			swap(a[ch1], a[v]);
			sift_down(ch1);
		}else{
			cout << v << " ";
		}
		return;
	}

	if(a[ch1] <= a[v] && a[ch2] <= a[v]){
		cout << v << " ";
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

void extract_max(){
	if(s == 0){
		cout << -1 << endl;
	}else{
		int mx = a[1];
		swap(a[1], a[s]);
		s--;
		if(s == 0){
			cout << 0 << " ";
		}else{
			sift_down(1);
		}
		cout << mx << endl;
	}
}

void insert_key(int x){
	if(s == n){
		cout << -1 << endl;
	}else{
		s++;
		a[s] = x;
		sift_up(s);
	}
}

void delete_key(int v){

}

int main(){
	int m;
	cin >> n >> m;
	s = 0;
	for(int i = 0; i < m; i++){
		int t;
		cin >> t;
		if(t == 1){
			extract_max();
		}else{
			int x;
			cin >> x;
			insert_key(x);
		}
	}

	for(int i = 1; i <= s; i++){
		cout << a[i] << " ";
	}

};
