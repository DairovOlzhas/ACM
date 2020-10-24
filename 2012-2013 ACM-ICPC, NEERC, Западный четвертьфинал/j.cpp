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
// typedef long long int ll; 
int X[2000005],Y[2000005]; 
  
// Find all possible sum of elements of a[] and store 
// in x[] 
void calcsubarray(int a[], int x[], int n, int c) 
{ 
    for (int i=0; i<(1<<n); i++) 
    { 
        ll s = 0; 
        for (int j=0; j<n; j++) 
            if (i & (1<<j)) 
                s += a[j+c]; 
        x[i] = s; 
    } 
} 
  
// Returns the maximum possible sum less or equal to S 
int solveSubsetSum(int a[], int n, int S) 
{ 
    // Compute all subset sums of first and second 
    // halves 
    calcsubarray(a, X, n/2, 0); 
    calcsubarray(a, Y, n-n/2, n/2); 
  
    int size_X = 1<<(n/2); 
    int size_Y = 1<<(n-n/2); 
  
    // Sort Y (we need to do doing binary search in it) 
    sort(Y, Y+size_Y); 
  
    // To keep track of the maximum sum of a subset 
    // such that the maximum sum is less than S 
    ll max = 0; 
  
    // Traverse all elements of X and do Binary Search 
    // for a pair in Y with maximum sum less than S. 
    for (int i=0; i<size_X; i++) 
    { 
        if (X[i] <= S) 
        { 
            // lower_bound() returns the first address 
            // which has value greater than or equal to 
            // S-X[i]. 
            int p = lower_bound(Y, Y+size_Y, S-X[i]) - Y; 
  
            // If S-X[i] was not in array Y then decrease 
            // p by 1 
            if (p == size_Y || Y[p] != (S-X[i])) 
                p--; 
  
            if ((Y[p]+X[i]) > max) 
                max = Y[p]+X[i]; 
        } 
    } 
    return max; 
} 
 

void solve(){
	int n,l;
	cin >> n >> l;

	int r[n], s[n], sumr = 0;
	for(int i = 0; i < n; i++){
		cin >> r[i];
		sumr += r[i];
	}

	int ans = 0;

	for(int i = 0; i < n; i++){
		cin >> s[i];
		ans += int(int((l+0.0)*r[i]/sumr) / s[i]) * s[i];
	}
	if(ans >= l){
		cout << ans;
		return;
	}

	// for(int i = 0; i < (1<<n); i++){
	// 	// int sm = 0;
	// 	// for(int j = 0; j < n; j++){
	// 	// 	if(i&(1<<j)){
	// 	// 		sm += s[j];
	// 	// 	}
	// 	// }

	// 	// if((abs(l-(sm+ans)) < mn) || (abs(l-(sm+ans)) == mn && best > ans+sm)){
	// 	// 	best = ans+sm;
	// 	// 	mn = abs(l-(sm+ans));
	// 	// }
	// }

	cout << ans + solveSubsetSum(s, n, l-ans);

}

  
 
int main(){
	freopen("splitter.in", "r", stdin);
	freopen("splitter.out", "w", stdout);
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
