#include <fstream>
#include <numeric>
#include <unordered_set>
#include <sstream>
#include <cassert>
#include <tuple>
#include <iomanip>
#include <random>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <chrono>
#include <stack>
#include <string>
#include <bitset>
#include <unordered_map>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>

#define rep(i,x,y) for(int i = x; i <= y; ++i)
#define repr(i,x,y) for(int i = x; i >= y; --i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x.size())
#define pb push_back
#define endl "\n" // interactive problem
#define ll long long
#define int long long

using namespace std;

const int N = (int)(1e6) + 322;
const int inf = (int)(1e9) + 322;
const long long INF = (long long)(1e18) + 322;
const int mod = (int)(1e9) + 7;
const double eps = 1e-10;


int n;

struct node {
    node *next[26];
    bool term;
    node() {
        for (int i = 0; i < 26; i++) {   //изначально заполняем next нулевыми указателями,
            next[i] = nullptr;           //так как следующие вершины ещё не созданы
        }
        term = false;
    }
};

node *root = new node();

void add(const string& s) {
    node *cur_v = root;     //текущая вершина
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        if (cur_v->next[c - 'a'] == nullptr) {
            cur_v->next[c - 'a'] = new node();
        }

        cur_v = cur_v->next[c - 'a'];
    }
    cur_v->term = true;
}

unordered_map<node*, bool> mapchik;
unordered_map<node*, ll> dp;


ll dfs(node *root, ll lvl = 0) {
    ll res = (1LL << (40 - lvl));
    dp[root] = res;

    ll sum = 0;
    bool leaf = true;
    for (int i = 0; i < 26; ++i) {
        if (root->next[i] == nullptr)
            continue;
        leaf = false;
        ll d = dfs(root->next[i], lvl + 1);
        sum += d;
    }
    if (leaf) {
        mapchik[root] = 1;
        return res;
    }
    if (res < sum)
        mapchik[root] = 1;
    return min(res, sum);
}

ll answer;
vector<string> ans;
string word;

void calc(node *root, string &word) {
    if (mapchik.count(root) or root->term) {
        answer += dp[root];
        ans.push_back(word);
        return;
    }
    for (int i = 0; i < 26; ++i) {
        if (root->next[i] == nullptr)
            continue;
        word += char(i+'a');
        calc(root->next[i], word);
        word.pop_back();
    }
}



void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        add(s);
    }
    dfs(root, 0);
    calc(root, word);
    cout << answer << endl;
    cout << (int)ans.size() << endl;
    for (auto it : ans)
        cout << it << endl;
}




signed main () {
//    ios_base :: sync_with_stdio(false);
//    cin.tie(0);
    // freopen("compression.in", "r", stdin);
    // freopen("compression.out", "w", stdout);
    int t = 1; //cin >> t;
    for(int tt = 1; tt <= t; ++tt) {
        solve();
    }
    return 0;
}