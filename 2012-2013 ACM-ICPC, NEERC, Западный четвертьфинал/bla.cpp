#include <iostream>
 
using namespace std;
 

int main(){

	int *n = new int();
	cin >> *n;

	int *arr = new int[*n];

	for(int i = 0; i < *n; i++){
		cin >> arr[i];
	}
	for(int i = 0; i < *n; i++){
		cout << arr[i] << " ";
	}

}
