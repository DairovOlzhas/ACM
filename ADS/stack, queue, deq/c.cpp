#include<iostream>
#include<vector>
using namespace std;

int main(){
	int data[2000000];
	int l = 1000000;
	int r = 1000000;

	while(1){
		string b;
		cin >> b;
		if(b == "push_back"){
			int a;
			cin >> a;
			data[r++] = a;
		    cout << "ok" << endl;
		    
		}
		if(b == "push_front"){
			int a;
			cin >> a;
			l--;
			data[l] = a;
		    cout << "ok" << endl;
		}
		if(b == "pop_front"){
			if(r == l)
				cout << "error" << endl;
			else{
				cout << data[l] << endl;
				l++;
			}
		}
		if(b == "pop_back"){
			if(r == l)
				cout << "error" << endl;
			else{
				cout << data[r-1] << endl;
				r--;

			}
		}
		if(b == "back")
			if(r == l)
				cout << "error" << endl;
			else
				cout << data[r-1] << endl;
		if(b == "front")
			if(r == l)
				cout << "error" << endl;
			else
				cout << data[l] << endl;

		if(b == "size")
				cout << abs(r - l) << endl;

		if(b == "clear"){
			l = 1000000;
			r = 1000000;
			cout << "ok" << endl;	
		}

		if(b == "exit"){
			
			cout <<  "bye" << endl;
			break;
		}
	}

	return 0;
}