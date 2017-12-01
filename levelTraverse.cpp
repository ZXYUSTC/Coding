#include<iostream>
#include<queue>
using namespace std;

typedef struct BTNode{
	int val;
	struct BTNode *lchild;
	struct BTNode *rchild;
	BTNode(int x){
		val=x;
		lchild=NULL;
		rchild=NULL;
	}
}BTNode;

void LevelTraverse(BTNode *root){
	if(root==NULL){
		return;
	}
	queue<BTNode *> q;
	q.push(root);
	q.push(NULL);
	while(q.size()>1){
		BTNode *t=q.front();
		if(t!=NULL){
			q.pop();
			cout<<t->val<<" ";
			if(t->lchild!=NULL)
				q.push(t->lchild);
			if(t->rchild!=NULL)
				q.push(t->rchild);
		}
		else{
			cout<<endl;
			q.pop();
			q.push(NULL);
		}
	}
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
	LevelTraverse(root);
	//system("pause");
	return 0;
}