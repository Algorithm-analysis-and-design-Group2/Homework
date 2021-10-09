#include<iostream>
using namespace std;
/*
void searchI(int a[], int low, int high) {
	int mid;
	if (low < high) {
		mid = (low + high) / 2;
		searchI(a, low, mid);
		searchI(a, mid + 1, high);
	}
	else
		if (a[low] == low)
			cout << "a[" << low << "]=" << low << endl;
}

int main() {
	int n;
	cout << "请输入数组中的元素个数：";
	cin >> n;
	cout << "请按照从小到大的顺序输入数组中的元素（整数元素互不相等）:" << endl;
	int a[50];
	for (int k = 0; k < n; k++) {
		cin >> a[k];
	}
	cout << endl;
	cout << "满足a[i]=i要求的元素：" << endl;
	searchI(a, 0, n - 1);
	return 0;
}*/
void searchI(int a[], int low, int high) {
	int mid = (low + high) / 2;
	if (low <= high) {
		if (a[mid] = mid) {
			cout << "满足a[i]=i要求的元素：";
			cout << "a[" << mid << "]=" << mid << endl;
		}
		else if (a[mid] > mid)
			searchI(a, low, mid - 1);
		else if (a[mid] < mid)
			searchI(a, mid + 1, high);
	}
	else
		cout << "该数组中没有符合要求的元素" << endl;
}

int main() {
	int n;
	cout << "请输入数组中的元素个数：";
	cin >> n;
	cout << "请按照从小到大的顺序输入数组中的元素（整数元素互不相等）:" << endl;
	int a[50];
	for (int k = 0; k < n; k++) {
		cin >> a[k];
	}
	cout << endl;
	
	searchI(a, 0, n - 1);
	return 0;
}