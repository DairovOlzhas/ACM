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

ull mod = 1e9+7;
 
using namespace std;

vector<string> ans;

class Node{
public:
	Node *childs[26];
	ull cnt, lvl;
	bool inans, isend;
	Node(ull levl){
		for(ull i = 0; i < 26; i++){
			childs[i] = NULL;
		}
		lvl = levl;
		inans = false;
		isend = false;
	}
};

Node *root;


void add(string s){
	Node *cur = root;
	for(ull i = 0; i < s.size(); i++){
		if(cur->childs[s[i]-'a'] == NULL){
			cur->childs[s[i]-'a'] = new Node(i+1);
		}
		cur = cur->childs[s[i]-'a'];
	}
	cur->isend = true;
}


ull dfs(Node *node){
	ull sum = 0;
	ull penalty = (1ll<<(40-node->lvl));
	for(ull i = 0; i < 26; i++){
		if(node->childs[i] != NULL){
			// cout << char('a'+i);
			sum = (sum + dfs(node->childs[i]));
		}
	}
	// cout << endl;
	if(node == root) return sum;
	if(sum == 0 || penalty <= sum || node->isend){
		node->inans = true;
	 	return penalty;
	}
	return sum;
}

void get_ans(Node *node, string s = ""){
	if(node->inans){
		ans.push_back(s);
		return;
	}

	for(int i = 0; i < 26; i++){
		if(node->childs[i] != NULL){
			get_ans(node->childs[i], s + char('a'+i));
		}
	}
}

void solve(){
	ull n;
	cin >> n;
	root = new Node(0);

	for(ull i = 0; i < n; i++){
		string s;
		cin >> s;
		add(s);
	}

	cout << dfs(root) << endl;

	get_ans(root);

	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i] << endl;
	}
}

  
 
int main(){
	 freopen("compression.in", "r", stdin);
	 freopen("compression.out", "w", stdout);
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
