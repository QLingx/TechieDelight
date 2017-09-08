#include<bits/stdc++.h>

using namespace std;

struct Node{
	int key;
	Node *left,*right;
};

Node *newNode(int key){
	Node * node = new Node;
	node->key = key;
	node->left = node->right = nullptr;
}

void insert(Node *&root,string level,int key){
	if(level.length() == 0){
		root = newNode(key);
		return;
	}

	int i = 0;
	Node *ptr = root;
	while(i < level.length()-1){
		if(level[i++] == 'L'){
			ptr = ptr->left;
		}else{
			ptr = ptr->right;
		}
	}
	if(level[i] == 'L'){
		ptr->left = newNode(key);
	}else{
		ptr->right = newNode(key);
	}
}

int isIdentical(Node *x,Node *y){
	if ( x == nullptr && y == nullptr){
		return 1;
	}

	return (x && y) && (x->key == y->key) &&
			isIdentical(x->left,y->left) &&
			isIdentical(x->right,y->right);
}

bool isIdentical_iter(Node *x,Node *y){
	if (x == nullptr && y == nullptr){
		return true;
	}
	if (x == nullptr){
		return false;
	}
	if (y == nullptr){
		return false;
	}

	stack<pair<Node*,Node*>> stack;
	stack.push({x,y});

	while(!stack.empty()){
		Node *x = stack.top().first;
		Node *y = stack.top().second;
		stack.pop();

		if(x->key != y->key){
			return false;
		}

		if(x->left && y->left){
			stack.push({x->left,y->left});
		}else if (x->left || y->left){
			return false;
		}

		if (x->right && y->right){
			stack.push({x->right,y->right})
		}else if(x->right || y->right){
			return false;
		}
	}
	return true;
}

int main(){
	Node *x = nullptr;
	vector<pair<string,int>>x_keys = {
			{"",15},{"L",10},{"R",20},{"LL",8},
			{"LR",12},{"RL",16},{"RR",25}
	};

	for(auto pair : x_keys){
		insert(x,pair.first,pair.second);
	}

	Node* y = nullptr;
	vector<pair<string,int>>y_keys = {
			{"",15},{"L",10},{"R",20},{"LL",8},
			{"LR",12},{"RL",16},{"RR",25}
	};

	for(auto pair: y_keys){
		insert(y,pair.first,pair.second);
	}

	if(isIdentical(x,y)){
		cout << "identical";
	}else{
		cout << "is not identical";
	}
	return 0;
}
