#include<iostream>
#include<cmath>

using namespace std;
	



class Node{
public:
	int val;
	Node *left, *right;

	Node(int val){
		this->val = val;
		left = NULL;
		right = NULL;
	}
};

class Tree{
public:
	Node *root;
	int sz;

	Tree(){
		root = NULL;
		sz = 0;
	}

	Node *insert(Node *node, int x){
	    if(node == NULL) {
	    	sz++;
	    	return new Node(x);
	    }
        if(x < node->val){
            node->left = insert(node->left, x);
        }else if(x > node->val){
            node->right = insert(node->right, x);
        }
	    return node;
	}


	int height(Node *node){
		if(node == NULL)
			return 0;
		return 1 + max(height(node->left), height(node->right));
	}

	int size(){
		return sz;
	}


	Node* maximum(Node *node){
		if(node->right == NULL) return node;
		return maximum(node->right);
	}

	Node* secondMax(Node *node){
		if(node->right == NULL) return maximum(node->left);
		if(node->right->right == NULL ){
			if (node->right->left == NULL) return node;
			else return maximum(node->right->left);
		}
		return secondMax(node->right);
	}

	void print_asc(Node *node){
		if(node == NULL) return;
		print_asc(node->left);
		cout << node->val  << endl;
		print_asc(node->right);
	}
};


int main(){
	int n;
	Tree *tree = new Tree();
	while(cin >> n){
		if(n == 0)
			break;
		tree->root = tree->insert(tree->root, n);
	}

	tree->print_asc(tree->root);
};
