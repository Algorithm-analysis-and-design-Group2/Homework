#include <iostream>
using namespace std;
int A[] = {1,2,3,4,5,6,7,8,9,10,11};
int B[11];

void print(int k) {
	int i;
	for (i = 0; i < k - 1; i++) {
		cout << B[i] << " ";
	}
	cout << B[k - 1] << endl;
}
void solve(int sum,int t,int k) {

	int i;
	if (sum>15) {
;		return;
	}
	if (sum == 15) {
		print(k);
		return;
	}
	for (i = t; i < 11; i++) {
		
		if (A[i] + sum <= 15) {
			B[k] = A[i];
			solve(A[i] + sum, i + 1, k + 1);
		}
	}
}
int main() {
	solve(0, 0, 0);
	return 0;
}