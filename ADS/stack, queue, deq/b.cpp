#include<iostream>
#include<vector>
using namespace std;

int main(){
	int data[1000000];
	int l = 0;
	int r = 0;

	while(1){
		string b;
		cin >> b;
		if(b == "push"){
			int a;
			cin >> a;
			data[r++] = a;
		    cout << "ok" << endl;
		}

		if(b == "pop"){
			if(r == l)
				cout << "error" << endl;
			else{
				cout << data[l] << endl;
				l++;
			}
		}

		if(b == "front")
			if(r == l)
				cout << "error" << endl;
			else
				cout << data[l] << endl;
			

		if(b == "size")
	 		cout << abs(r - l) << endl;
			

		if(b == "clear"){
			l = 0;
			r = 0;
			cout << "ok" << endl;	
		}

		if(b == "exit"){
			
			cout <<  "bye" << endl;
			break;
		}
	}

	return 0;
}