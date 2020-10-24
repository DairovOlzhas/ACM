#include<iostream>
#include<vector>
using namespace std;


class Node{
public:
	int val;
	Node* next;

	Node(int val){
		this->val = val;
		next = NULL;
	}
};


class Queue{
public:
	Node *head, *tail;

	Queue(){
		head = tail = NULL;
	}

	void push(int val){
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

	int front(){
		return head->val;
	}

	void pop(){
		if(head != NULL){
			head = head->next;
		}
	}
};

int main(){

	Queue *q1 = new Queue(), *q2 = new Queue();

	for(int i = 0; i < 10; i++){
		int x;
		cin >> x;
		if(i < 5){
			q1->push(x);
		}else{
			q2->push(x);
		}
	}

	for(int i = 0; i < 1e6+1; i++){
		int c1 = q1->front(), c2 = q2->front();
		q1->pop();
		q2->pop();
		if((c1 == 9 && c2 == 0) || (c1 < c2 && !(c1==0 && c2==9))){
			q2->push(c1);
			q2->push(c2);
		}else{
			q1->push(c1);
			q1->push(c2);
		}
		if(q1->empty()){
			cout << "second" << " " << i+1;
			return 0;
		}
		if(q2->empty()){
			cout << "first" << " " << i+1;
			return 0;
		}
	}

	cout << "batva";

	return 0;
}