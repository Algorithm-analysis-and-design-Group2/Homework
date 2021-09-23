#include<iostream>
using namespace std;

bool Recursion(int A[], int num, int targetSum);
void Question1(int A[], int num, int targetSum){
	// 首先进行排序
	for (int j = num - 1; j > 0; j--) {
		for (int i = 0; i < j; i++) {
			int t;
			if (A[i] > A[i + 1]) {
				t = A[i + 1];
				A[i + 1] = A[i];
				A[i] = t;
			}
		}
	}
	//for(int i =0; i<num;i++)
	//cout << A[i];
	if (!Recursion(A, num, targetSum)) printf("Not Found");
}
bool Recursion(int A[], int num, int targetSum){
	int accSum = 0;
	int accNum = 0;
	int i = 0;
	while (accSum < targetSum && i<num) {
		if (A[i] != 0) {
			accSum += A[i];
			accNum++;
		}
		i++;
	}
	//cout << accNum<<" "<<accSum<<endl;
	if (accSum == targetSum) {
		int i = 0, j=0;
		while(i<accNum && j<num) {
			if (A[j] != 0) {
				printf("%d, ", A[j]);
				i++;
			}j++;
		}
		printf("count=%d", accNum);
		return true;
	}
	else if (accSum > targetSum) {
		int i = 0, j = 0;
		while(i < accNum && j < num) {
			if (A[j] != 0) {
				int t = A[j];
				A[j] = 0;
				if (Recursion(A, num, targetSum)) return true;
				else A[j] = t;
				i++;
			}j++;
		}return false;
		}
     else if (i >= num) {
		return false;
	}
}
int main(){
	int A[] = { 3,4,1,5,2};
	Question1(A, 5, 6);
	return 0;
}