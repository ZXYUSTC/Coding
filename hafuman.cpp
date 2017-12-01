#include<iostream>
#include<vector>
using namespace std;

void HeapAdjust(vector<int> &A,int i,int size){
	int lchild=2*i;
	int rchild=2*i+1;
	int min=i;
	if(i<=(size-1)/2){
		if(lchild<=(size-1)&&A[lchild]<A[min]){
			min=lchild;
		}
		if(rchild<=(size-1)&&A[rchild]<A[min]){
			min=rchild;
		}
		if(min!=i){
			swap(A[i],A[min]);
			HeapAdjust(A,min,size);
		}
	}
}

void BuildHeap(vector<int> &A,int size){
	for(int i=(size-1)/2;i>=0;i--){
		HeapAdjust(A,i,size);
	}
}
/*
void HeapSort(vector<int> &A,int size){
	BuildHeap(A,size);
	for(int i=size-1;i>=0;i--){
		swap(A[i],A[0]);
		HeapAdjust(A,0,i);
	}
}*/

int Hafuman(vector<int> &A,int size){
	BuildHeap(A,size);
	while(A.size()>1){
		int s=A.size();
		swap(A[0],A[s-1]);
		HeapAdjust(A,0,s-1);
		swap(A[0],A[s-2]);
		A[s-2]=A[s-1]+A[s-2];
		auto p=A.end()-1;
		A.erase(p);
		HeapAdjust(A,0,s-2);

	}
	return A[0];

}
int main(){
	vector<int> A={4,10,4,3,2,14,5};
	//HeapSort(A,A.size());
	cout<<Hafuman(A,A.size());
	cout<<endl;
	return 0;
}