#include<iostream>
#include<vector>
using namespace std;

void SubSet(vector<int> &A) {
	int l = pow(2, A.size());
	for (int i = 0; i < l; i++) {
		int tmp = i;
		int k = 0;
		while (tmp) {
			if (tmp % 2 == 1) {
				cout << A[k] << " ";
			}
			k++;
			tmp = tmp / 2;
		}
		cout << endl;
	}
}
int main() {
	vector<int> A = { 1,2,3,4 };
	SubSet(A);
	system("pause");
	return 0;
}