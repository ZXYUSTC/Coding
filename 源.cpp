#include<iostream>
#include<stack>
#include<queue>
using namespace std;
typedef struct BTNode {
	int val;
	struct BTNode *lchild;
	struct BTNode *rchild;
	BTNode(int x){
		val = x;
		lchild = NULL;
		rchild = NULL;
	}
}BTNode;
void Print(BTNode *root) {
	//stack<BTNode *> s;
	queue<BTNode *> q;
	queue<BTNode *> r;
	stack<BTNode *> s;
	q.push(root);
	q.push(NULL);
	int flag = 1;
	while (q.size() > 1||s.size()>0) {
		BTNode *tmp = q.front();
		q.pop();
		if (flag == 1) {
			if (tmp != NULL) {
				cout << tmp->val << " ";
				if (tmp->lchild != NULL) {
					q.push(tmp->lchild);
				}
				if (tmp->rchild != NULL) {
					q.push(tmp->rchild);
				}
			}
			else {
				flag = 0;
				q.push(NULL);
			}
		}
		else {
			if (tmp != NULL) {
				s.push(tmp);
				r.push(tmp);
			}
			else {
				while (s.empty() != 1) {
					BTNode *t = s.top();
					s.pop();
					
					//r.pop();
					cout << t->val << " ";
					t = r.front();
					r.pop();
					if (t->lchild != NULL) {
						q.push(t->lchild);
					}
					if (t->rchild != NULL) {
						q.push(t->rchild);
					}
				}
				q.push(NULL);
				flag = 1;
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
	Print(root);
	system("pause");
	return 0;
}