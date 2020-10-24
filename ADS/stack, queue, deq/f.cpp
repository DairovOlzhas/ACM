#include<iostream>
#include<vector>
using namespace std;


class Node{
public:
	char val;
	Node* next;

	Node(char val){
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

	void push(char val){
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

	char top(){
		if(tail!=NULL)
			return tail->val;
		return '0';
	}

	void pop(){
		if(tail != NULL){
			tail = tail->next;
		}
	}
};

int main(){

	Stack *stack = new Stack();

	string s;
	cin >> s;

//	((((
//	((((
	for(int i = 0; i < s.size(); i++){
		char t = stack->top();
		if((t=='(' && s[i] == ')') || (t=='[' && s[i] == ']') || (t=='{' && s[i] == '}')){
			stack->pop();
		}else{
			stack->push(s[i]);
		}
	}

	if(stack->empty()){
		cout << "yes";
	}else{
		cout << "no";
	}

	return 0;
}