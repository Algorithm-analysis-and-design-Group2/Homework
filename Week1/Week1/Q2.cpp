#include<iostream>
using namespace std;

bool Question2(int A[], int start, int end, int& numOfChange) {
	while (A[start] == A[end] && end - start >= 1) {
		start++;
		end--;
	}
	if (end - start < 1) return true;

	if (A[start] < A[end]) {
		int t = A[start] + A[start + 1];
		A[start] = 0;
		A[start + 1] = t;
		numOfChange++;
		Question2(A, start + 1, end, numOfChange);
	}
	else {
		int t = A[end] + A[end - 1];
		A[end] = 0;
		A[end - 1] = t;
		numOfChange++;
		Question2(A, start, end - 1, numOfChange);
	}
}

int main() {
	int A[] = { 1,2,3,4,6 };
	int numOfChange = 0;
	Question2(A, 0, 4, numOfChange);
	for (int i = 0; i < 5; i++) {
		if(A[i] != 0)
		printf("%d ", A[i]);
	}
	printf("\nNumber of Changes:%d",numOfChange);
	return 0;
}