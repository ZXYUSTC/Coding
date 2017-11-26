class Solution {
public:
	/*
	* @param A: an array
	* @return: total of reverse pairs
	*/
	long long result = 0;
	void Merge(vector<int> &A, int p, int q, int r) {
		int *t = new int[r - p + 1]();
		int k = 0;
		int i = p, j = q + 1;
		//long long result=0;
		while (i <= q&&j <= r) {
			if (A[i] <= A[j]) {
				t[k++] = A[i++];
			}
			else {
				result += q - i + 1;
				t[k++] = A[j++];
				//result+=;
			}
		}
		while (i <= q) {
			t[k++] = A[i++];
		}

		while (j <= r)
			t[k++] = A[j++];
		//result++;
		k = 0;
		while (k<r - p + 1) {
			A[k + p] = t[k];
			k++;
		}
	}
	void MergeSort(vector<int> &A, int p, int q) {
		if (p<q) {
			int mid = (p + q) / 2;
			MergeSort(A, p, mid);
			MergeSort(A, mid + 1, q);
			Merge(A, p, mid, q);
		}
	}
	long long reversePairs(vector<int> &A) {
		// write your code here
		MergeSort(A, 0, A.size() - 1);
		return result;
	}
};