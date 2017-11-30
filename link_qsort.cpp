#include<iostream>
using namespace std;
typedef struct Node{
	int val;
	struct Node *next;
	Node(int x){
		val=x;
		next=NULL;
	}
}Node;

Node *Partion(Node *s,Node *e){
	int key=s->val;
	Node *p=s;
	Node *q=p->next;
	while(q!=e){
		if(q->val<key){
			p=p->next;
			swap(p->val,q->val);
		}
		q=q->next;
	}
	swap(s->val,p->val);
}
void qsort(Node *s,Node *e){
	if(s!=e){
		Node *p=Partion(s,e);
		qsort(s,p);
		qsort(p->next,e);
	}
}
int main(){
	Node* head=new Node(9);
	head->next=new Node(0);
	head->next->next=new Node(6);
	head->next->next=new Node(4);
	qsort(head,NULL);
	Node *p=head;
	while(p!=NULL){
		cout<<p->val<<" ";
		p=p->next;
	}
	return 0;
}