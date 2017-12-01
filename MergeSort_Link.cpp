#include<iostream>
using namespace std;
typedef struct Node{
	int val;
	struct Node* next;
	Node(int x){
		val=x;
		next=NULL;
	}
}Node;
void Merge(Node *p, Node *q, Node *r){
	Node *s1=p, *s2=p->next;
	Node *head=new Node(0);
	Node *s=head;	}

	while(s1!=q&&s2!=r){
		if(s1->val<=s2->val){
			s->next=s1;
			s1=s1->next;
		}else{
			s->next=s2;
			s2=s2->next;
		}
		s=s->next;
	}
	if(s1!=q)
		s->next=s1;
	if(s2!=r){
		s->next=s2;
	}
}
Node *getMidNode(Node *s, Node *e){
	if(s->next==NULL){
		return s;
	}
	if(s->next==e){
		return s;
	}
	
	if(s->next->next==e){
		return s->next;
	}
	Node *p=s,*q=s;
	while(p!=e){
		p=p->next->next;
		q=p->next;
	}
	return q;
}
void MergeSort(Node *s, Node *e){
	if(s!=e){
		Node *m=getMidNode(s,e);
		MergeSort(s,m);
		MergeSort(m,e);
		Merge(s,m,e);
	}
	
}
