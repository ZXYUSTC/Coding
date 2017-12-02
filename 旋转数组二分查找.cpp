#include<iostream>
#include<vector>
using namespace std;

int getResult(const vector<int> &A, int key) {
	int i = 0;
	int j = A.size() - 1;
	while (i <= j) {
		int mid = (i + j) / 2;
		if (A[mid] == key)
			return mid;
		else {
			if (A[mid] > A[i]) {
				if (key >= A[i] && key <= A[mid]) {
					j = mid - 1;
				}
				else {
					i = mid + 1;
				}
			}
			else {
				if (key >= A[mid] && key <= A[j]) {
					i = mid + 1;
				}
				else {
					j = mid - 1;
				}
			}
		}
	}
	return -1;
}
int main() {
	vector<int> A = { 3,4,5,1,2 };
	int key;
	cin >> key;
	cout << getResult(A, key) << endl;
	system("pause");
	return 0;
}