/*
*����һ�����������У�������������0�͸����������һ���������������г˻���
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	vector<float> A = { -2.5, 4, 0, 3, 0.5, 8, - 1 };
	int len = A.size();
	float *Max = new float[len]();
	float *Min = new float[len]();
	float res = A[0];
	Max[0] = Min[0] = A[0];
	for (int i = 1; i < len; i++) {
		Max[i] = max(A[i], max(Max[i - 1] * A[i], Min[i - 1] * A[i]));
		Min[i] = min(A[i], min(Max[i - 1] * A[i], Min[i - 1] * A[i]));
		res = max(Max[i], res);
	}
	cout << res << endl;
	system("pause");
	return 0;
}