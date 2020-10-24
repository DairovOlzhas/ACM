#include<iostream>
#include<vector>

using namespace std;


int main(){

	int data[1000];
	int size;
	vector<string> v;

	while(1){
		string b;
		cin >> b;
		if(b == "push"){
			int a;
			cin >> a;
			data[size++] = a;
		    cout << "ok" << endl;
		}

		if(b == "pop"){
			if(size == 0)
				cout << "error" << endl;
			else{
				--size;
				cout << data[size] << endl;
			}
		}

		if(b == "back")
			if(size == 0)
				cout << "error" << endl;
			else
				cout << data[size - 1] << endl;
			

		if(b == "size")
	 		cout << size << endl;
			

		if(b == "clear"){
			size = 0;
			cout << "ok" << endl;	
		}

		if(b == "exit"){
			for(int i = 0; i < v.size(); i++){
				cout << v[i] << endl;
			}
			cout <<  "bye" << endl;
			break;
		}
	}

	return 0;
}