#include<iostream>
#include<vector>
using namespace std; 
void Print(vector<int> &A,int index)
{
	if (index >= A.size()) {
		for (int i = 0; i < A.size(); i++)
			cout << A[i] << " ";
		cout << endl;
	}else {
		for (int i = index; i < A.size(); i++) {
			swap(A[i], A[index]);
			Print(A, index + 1);
			swap(A[i], A[index]);
		}
	}
}
int main() {
	vector<int> A = { 1,2,3 ,4};
	Print(A, 0);
	system("pause");
	return 0;
}