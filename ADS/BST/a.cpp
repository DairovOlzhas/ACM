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

	Node *insert(Node *root, int x){
	    if(root == NULL) {
	    	
	    	return new Node(x);
	    }
        if(x < root->val){
            root->left = insert(root->left, x);
        }else if(x > root->val){
            root->right = insert(root->right, x);
        }
	    return root;
	}


	int height(Node *node){
		if(node == NULL)
			return 0;
		return 1 + max(height(node->left), height(node->right));
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

	cout << tree->height(tree->root);

};
