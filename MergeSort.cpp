#include<iostream>
#include<vector>
using namespace std;
int result=0;
void Merge(vector<int> &A,int p, int q, int r){
    int *t=new int[r-p+1]();
    int k=0;
    int i=p,j=q+1;
        //long long result=0;
        while(i<=q&&j<=r){
                if(A[i]<=A[j]){
                    t[k++]=A[i++];
                }
                else{
                    t[k++]=A[j++];
                    result++;
                }
        }
        while(i<=q)
            t[k++]=A[i++];
        while(j<=r)
            t[k++]=A[j++];
        k=0;
        while(k<r-p+1){
            A[k+p]=t[k];
            k++;
        }
    }
    void MergeSort(vector<int> &A, int p, int q){
        if(p<q){
            int mid=(p+q)/2;
            MergeSort(A,p,mid);
            MergeSort(A,mid+1,q);
            Merge(A,p,mid,q);
        }
    }
    int main(){
		//vector<int> B={2,4,1,3,5};
		vector<int> A;
		A.push_back(2);
		A.push_back(4);
		A.push_back(1);
		A.push_back(3);
		A.push_back(5);
		MergeSort(A,0,4);
		for(int i=0;i<5;i++)
			cout<<A[i]<<" ";
		return 0;
	}
