/**
#include <iostream>
using namespace std;

int sumcount = 0;

bool issame(int A[],int n) {
	int count = 0;
	int B[100];
	bool same = false;
	for (int i = 0; i < n; i++) {
		B[i] = A[n - i - 1];
	}
	for (int i = 0; i < n; i++) {
		if (A[i] == B[i])
			count++;
	}
	if (count == n) {
		same = true;
	}
	return same;
}

void solve(int A[],int a) {
	
	A[0] += A[1];
	for (int i = 1; i < a-1; i++) {
		A[i] = A[i + 1];		
	}
	a--;
	sumcount++;
	for (int i = 0; i < a; i++)
		cout << A[i] << " ";
	cout << endl;
	
	if (issame(A,a)) {
		
		cout << "选择次数：" << sumcount << endl;
		cout << "最后数列状态位：";
		for (int i = 0; i < a; i++) {
			cout << A[i] << " ";
		}
		cout << endl;

	}else{
		solve(A, a);		
	}
}

int main() {
	int s;
	cout << "请输入数列中元素个数：";
	cin >> s;
	int A[100];
	cout << "请依次输入数列中的元素：";
	for (int i = 0; i < s; i++) {
		cin>>A[i];
	}
	solve(A, s);
	return 0;
}*/

#include <iostream>
using namespace std;

int sumcount = 0;
int s;
int suminit = 0;
bool issame(int A[], int n) {
	int count = 0;
	int B[10];
	bool same = true;
	for (int i = 0; i < n; i++) {
		B[i] = A[n - i - 1];
	}
	for (int i = 0; i < n; i++) {
		if (A[i] != B[i]) {
			same = false;
			return same;
		}
	}
	return same;
}

void solve(int A[], int n) {
	
	if (n < 3) {
		return;
	}
	else if (issame(A, n)) {
		
		cout << "选择次数：" << sumcount << endl;
		cout << "最后数列状态位：";
		for (int i = 0; i < n; i++) {
			cout << A[i] << " ";
		}
		cout << endl;
	}
	else {
		for (int i = 0; i < n; i++) {
			int C[10];
			
			C[i] = A[i] + A[i + 1];
			for (int j = i + 1; j < n - 1; j++) {
				C[j] = A[j + 1];
			}
			sumcount++;
			solve(C, n - 1);
			C[i] = A[i];
			for (int j = i + 1; j < n; j++) {
				C[j] = A[j];
			}
			sumcount--;
		}
	}
}

int main() {

	cout << "请输入数列中元素个数：";
	cin >> s;
	int A[10];

	cout << "请依次输入数列中的元素：";
	for (int i = 0; i < s; i++) {
		cin >> A[i];
		suminit += A[i];
	}
	solve(A, s);
	return 0;
}

