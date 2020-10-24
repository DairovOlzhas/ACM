#include <iostream>

using namespace std;

int main(){

    int a,b;
    cin >> a >> b;

    if(a > b) swap(a,b);

    int n = b;
    while(n%a!=0) n+=b;
    cout << n;
}