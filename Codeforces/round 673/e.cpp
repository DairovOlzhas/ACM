#include <bits/stdc++.h>
#include <iostream>
// #include <unordered_map>
#define vi vector <ull>
#define ii pair<ull,ull>
#define vii vector<ii>
 
#define seti set<ull>
#define mii map<ull,ull>
#define um unordered_map
#define ll long long
#define ull  long long
#define fi first
#define se second
#define pb push_back
// #define mp make_pair
#define MAX 100100
#define _ << " " <<

// typedef for(n) for(int i = 0; i < n; i++)


ull mod = 1e9+7;
 
using namespace std;



class Node {
public:
	ull depth;
	Node *childs[2];
	vector<ull> v; 
	Node(){}
	Node(ull d){
		childs[0] = childs[1] = NULL;
		depth = d;
	}

	void add(ull x){
		v.push_back(x);
	}
};

Node *root = new Node();

ull sum[30][2];

void add(ull val, ull pos){
	Node *cur = root;

	for(ull i = 29; i >= 0; i--){
		bool a = val&(1ll<<i);
		if(cur->childs[a] == NULL){
			cur->childs[a] = new Node(i);
			cur->depth = 29-i;
		}
		cur = cur->childs[a];
		cur->v.push_back(pos);
	}
}

void sort_v(Node *node){
	if(node == NULL) return;
	sort(node->v.begin(), node->v.end());
	sort_v(node->childs[0]);
	sort_v(node->childs[1]);
}


void calc(Node *node){
	if(node == NULL) return;

	if(node->childs[0] && node->childs[1]){
		vector<ull> v1 = node->childs[0]->v, v2 = node->childs[1]->v;
		ull l = 0,r = 0;
		while(l < v1.size() || r < v2.size()){
			if(v1[l] <= v2[r]){
				sum[node->depth][0] += r;
				l++;
			}else{
				r++;
				sum[node->depth][0] += 1;
			}
		}

		l = 0, r = 0;

		while(l < v2.size() || r < v1.size()){
			if(v2[l] <= v1[r]){
				sum[node->depth][1] += r;
				l++;
			}else{
				r++;
				sum[node->depth][1] += 1;
			}
		}

	}	

	calc(node->childs[0]);
	calc(node->childs[1]);
}

void solve(){

	ull n;
	cin >> n;

	ull a[n];

	for(ull i = 0; i < n; i++){
		cin >> a[i];
		add(a[i], i);
	}

	sort_v(root);


	calc(root);
	ull ans = 0;
	ull cnt = 0;

	// for(int i = 0; i < 30; i++){
	// 	cout << sum[i][0] _ sum[i][1] << endl;
	// }



	for(int i = 0; i < 30; i++){
		if(sum[i][1] < sum[i][0]){
			ans = (ans|(1ll<<i));
			cnt += sum[i][1];
		}
			cnt += sum[i][0];
	}
	cout << cnt _ ans << endl;
}

  
 
int main(){
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ull q;
	// cin >> q;
	q = 1;
	for(ull i = 0; i < q; i++){
		// cout << "Case #" << i+1 << ":" << endl;
		
 
		solve();
		// cout << endl;
	}
 
	
 
	return 0;
}
	