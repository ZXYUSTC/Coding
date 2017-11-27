#include<iostream>
#include<vector>
using namespace std;

int Partition(vector<int> &A,int s, int e)
{
	int i=s, j=e;
	int key=A[i];
	while(i<j){
		while(i<j&&A[j]>=key)
			j--;
		A[i]=A[j];
		while(i<j&&A[i]<=key)
			i++;
		A[j]=A[i];
	}
	A[i]=key;
	return i;
}

void qsort(vector<int> &A,int s,int e){
	if(s<e){
		int mid=Partition(A,s,e);
		qsort(A,s,mid-1);
		qsort(A,mid+1,e);
	}
}

int main(){
	vector<int> A({12, 3, 5, 8, 10});
	qsort(A,0,4);
	for(int i=0;i<A.size();i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;
	return 0;
}
