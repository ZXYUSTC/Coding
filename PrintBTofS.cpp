#include<iostream>
#include<queue>
#include<stack>
using namespace std;
typedef struct BTNode{
	int val;
	struct BTNode *lchild;
	struct BTNode *rchild;
	BTNode(int x){
		val = x;
		lchild = NULL;
		rchild = NULL;
	}
}BTNode;

void PrintBT(BTNode *root){
	if (root == NULL)
		return;
	int flag = 1;
	queue<BTNode *> q;
	stack<int> s;
	q.push(root);
	q.push(NULL);
	while (q.size() > 1){
		BTNode *t=q.front();
		q.pop();
		if (t != NULL){
			if (flag == 1){
				cout << t->val<<" ";
			}
			else{
				s.push(t->val);
			}
			if (t->lchild!=NULL){
				q.push(t->lchild);
			}
			if (t->rchild != NULL){
				q.push(t->rchild);
			}
		}
		else{
			if (flag == 1){
				flag = 0;
				cout << endl;
				q.push(NULL);
			}
			else{
				while (s.size() > 0){
					cout << s.top() << " ";
					s.pop();
				}
				flag = 1;
				cout << endl;
				q.push(NULL);
			}
		}
	}
	while (s.size() > 0){
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
}

int main(){
	BTNode* root = new BTNode(1);
	root->lchild = new BTNode(2);
	root->rchild = new BTNode(3);
	root->lchild->lchild = new BTNode(4);
	root->lchild->rchild = new BTNode(5);
	root->rchild->lchild = new BTNode(6);
	root->rchild->rchild = new BTNode(7);
	root->lchild->lchild->lchild = new BTNode(8);
	root->rchild->rchild->rchild = new BTNode(9);
	PrintBT(root);
	system("pause");
	return 0;
}