/**#include<iostream>
using namespace std;

void Simple(int a[], int low, int high) {
	//简单选择排序
	for (int i = low; i <= high; i++) {
		int min = i;
		for (int j = i + 1; j <= high; j++) {
			if (a[j] < a[min]) {
				min = j;
			}
		}
		if (min != i) {
			int temp = a[i];
			a[i] = a[min];
			a[min] = temp;
		}
	}
}
void SimpleSort(int a[], int low, int high) {
	//划分为子问题
	int mid;
	if (low < high) {
		mid = (low + high) / 2;
		SimpleSort(a, low, mid);
		SimpleSort(a, mid + 1, high);
		Simple(a, low, high);
	}
}

int main1() {
	
	int n;
	cout << "请输入要排序的数组元素个数：";
	cin >> n;
	int a[50];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	SimpleSort(a, 0, n - 1);
	cout << "从小到大排序结果：";
	for (int j = 0; j < n; j++) {
		cout << a[j] << " ";
	}
	cout << endl;
	return 0;
}*/