#include<iostream>
#include<stack>
using namespace std;
typedef struct BTNode {
	int val;
	struct BTNode *lchild;
	struct BTNode *rchild;
	BTNode(int x) {
		val = x;
		lchild = NULL;
		rchild = NULL;
	}
}BTNode;

void PostTraverse(BTNode *root) {
	if (root == NULL) {
		return;
	}
	stack<BTNode *> s;
	s.push(root);
	BTNode *last = root;
	while (s.empty() != 1) {
		BTNode *t = s.top();
		if(t->lchild==NULL&&t->rchild==NULL||t->rchild==NULL&&t->lchild==last||t->rchild==last){
			cout << t->val << " ";
			last = t;
			s.pop();
		}
		else {
			if (t->rchild != NULL) {
				s.push(t->rchild);
			}
			if (t->lchild != NULL) {
				s.push(t->lchild);
			}
		}
	}
}

int main() {
	BTNode* root = new BTNode(1);
	root->lchild = new BTNode(2);
	root->rchild = new BTNode(3);
	root->lchild->lchild = new BTNode(4);
	root->lchild->rchild = new BTNode(5);
	root->rchild->lchild = new BTNode(6);
	root->rchild->rchild = new BTNode(7);
	root->lchild->lchild->lchild = new BTNode(8);
	root->rchild->rchild->rchild = new BTNode(9);
	PostTraverse(root);
	system("pause");
	return 0;
}