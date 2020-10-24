#include<iostream>
#include<vector>
using namespace std;


class Node{
public:
	string val;
	Node* next;

	Node(string value){
		this->val = value;
		next = NULL;
	}
};


class Queue{
public:
	Node *head, *tail;

	Queue(){
		head = tail = NULL;
	}

	void push(string val){
		if(tail == NULL){
			head = tail = new Node(val);
		}else{
			tail->next = new Node(val);
			tail = tail->next;
		}
	}

	bool empty(){
		return head == NULL;
	}

	string front(){
		if(head != NULL)
			return head->val;
	}

	void pop(){
		if(head != NULL){
			head = head->next;
		}
	}
};

int main(){


	Queue *cl9 = new Queue();
	Queue *cl10 = new Queue();
	Queue *cl11 = new Queue();

	int n;
	string s;

	while(cin >> n){
		cin >> s;
		if(n == 9){
			cl9->push(s);
		}else if(n == 10){
			cl10->push(s);
		}else{
			cl11->push(s);
		}
	}

	while(!cl9->empty()){
		cout << 9 << " " << cl9->front() << endl;
		cl9->pop();
	}
	while(!cl10->empty()){
		cout << 10 << " " << cl10->front() << endl;
		cl10->pop();
	}
	while(!cl11->empty()){
		cout << 11 << " " << cl11->front() << endl;
		cl11->pop();
	}
	return 0;
}