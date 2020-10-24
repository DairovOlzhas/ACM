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

	void printAsc(Node *node){
		if(node == NULL) return;
		printAsc(node->left);
		cout << node->val  << endl;
		printAsc(node->right);
	}


	void printLeafAsc(Node *node){
		if(node == NULL) return;
		printLeafAsc(node->left);
		if(node->left==NULL && node->right==NULL){
			cout << node->val << endl;
		}
		printLeafAsc(node->right);
	}

	void printRazvilkaAsc(Node *node){
		if(node == NULL) return;
		printRazvilkaAsc(node->left);
		if(node->left != NULL && node->right != NULL ){
			cout << node->val << endl;
		}
		printRazvilkaAsc(node->right);
	}

	void printVetkiAsc(Node *node){
		if(node == NULL) return;
		printVetkiAsc(node->left);
		int cnt = 0;
		if(node->left != NULL) cnt++;
		if(node->right != NULL) cnt++;
		if(cnt == 1){
			cout << node->val << endl;
		}
		printVetkiAsc(node->right);
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

	tree->printVetkiAsc(tree->root);

};
