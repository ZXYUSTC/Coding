/*
*螺旋打印二维数组
*/
#include<iostream>
#include<vector>
using namespace std;
void PrintMatrix(vector<vector<int>> A, int m, int n) {
	int xBegin = 0;
	int xEnd = n - 1;
	int yBegin = 0;
	int yEnd = m - 1;
	while (xBegin<xEnd || yBegin<yEnd) {
		if (xBegin <= xEnd) {
			for (int x = xBegin; x<=xEnd; x ++) {
				cout << A[yBegin][x] << " ";
			}
			yBegin++;
		}
		if (yBegin <= yEnd) {
			for (int y = yBegin; y <= yEnd; y++) {
				cout << A[y][xEnd] << " ";
			}
			xEnd--;
		}
		if (xBegin <= xEnd) {
			for (int x = xEnd; x >= xBegin; x--) {
				cout << A[yEnd][x] << " ";
			}
			yEnd--;
		}
		if (yBegin <= yEnd) {
			for (int y = yEnd; y >= yBegin; y--) {
				cout << A[y][xBegin] << " ";
			}
			xBegin++;
		}
	}
}

int main() {
	vector<vector<int>> A = { { 1,2,3,4 },{ 5,6,7,8 },{ 9,10,11,12 },{ 13,14,15,16 } };
	PrintMatrix(A, 4, 4);
	cout << endl;
	system("pause");
	return 0;
}
