#include<iostream>
#include<vector>
#include<sstream>
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


class Stack{
public:
	Node *tail;

	Stack(){
		tail = NULL;
	}

	void push(int val){
		Node *node = new Node(val);

		if (tail == NULL) tail = node;
		else{
			node->next = tail;
			tail = node;
		}
	}

	bool empty(){
		return tail == NULL;
	}

	int top(){
		if(tail!=NULL)
			return tail->val;
		return -1;
	}

	void pop(){
		if(tail != NULL){
			tail = tail->next;
		}
	}
};

// 8 9 + 1 3 100 - * +
// stack: -80 

int main(){
	Stack *stack = new Stack();
	
	string s;
	while(cin >> s){
		if(s == "*"){
			int a = stack->top();
			stack->pop();
			int b = stack->top();
			stack->pop();
			stack->push(a*b);
		}else if(s=="-"){
			int a = stack->top();
			stack->pop();
			int b = stack->top();
			stack->pop();
			stack->push(b-a);
		}else if(s == "+"){
			int a = stack->top();
			stack->pop();
			int b = stack->top();
			stack->pop();
			stack->push(a+b);
		}else{
			int x;
			stringstream ss;
			ss << s;
			ss >> x;
			stack->push(x);
		}
	}

	cout << stack->top();


	return 0;
}