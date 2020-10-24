#include<iostream>
#include<cmath>

using namespace std;
	

int a[400010];
int n, s;


int sift_up(int v){
	int parent = v/2;
	if(parent == 0) {
		return v;
	}
	if(a[parent] < a[v]){
		swap(a[parent], a[v]);
		return sift_up(parent);
	}else{
		return v;
	}
}

int sift_down(int v){
	int ch1 = v*2, ch2 = v*2+1;
	if(ch1 > s) {
		return v;
	}

	if(ch2 > s) {
		if(a[ch1] > a[v]){
			swap(a[ch1], a[v]);
			return sift_down(ch1);
		}
		return v;
	}

	if(a[ch1] <= a[v] && a[ch2] <= a[v]){
		return v;
	}

	if(a[ch1] < a[ch2]){
		swap(a[ch2], a[v]);
		return sift_down(ch2);
	}else{
		swap(a[ch1], a[v]);
		return sift_down(ch1);
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
			cout << sift_down(1) << " ";
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
		cout << sift_up(s) << endl;
	}
}

void delete_key(int v){
	if(v > s || v <= 0){
		cout << -1 << endl;
	}else{
		cout << a[v] << endl;
		int d = a[v];
		swap(a[v], a[s]);
		s--;
		if(a[v] > d){
			int res = sift_up(v);
		}else if(a[v] < d){
			int res = sift_down(v);
		}
	}
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
		}else if(t == 2){
			int x;
			cin >> x;
			insert_key(x);
		}else{
			int x;
			cin >> x;
			delete_key(x);
		}
	}

	for(int i = 1; i <= s; i++){
		cout << a[i] << " ";
	}

};
