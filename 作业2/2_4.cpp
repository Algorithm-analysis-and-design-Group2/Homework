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
	cout << "�����������е�Ԫ�ظ�����";
	cin >> n;
	cout << "�밴�մ�С�����˳�����������е�Ԫ�أ�����Ԫ�ػ�����ȣ�:" << endl;
	int a[50];
	for (int k = 0; k < n; k++) {
		cin >> a[k];
	}
	cout << endl;
	cout << "����a[i]=iҪ���Ԫ�أ�" << endl;
	searchI(a, 0, n - 1);
	return 0;
}*/
void searchI(int a[], int low, int high) {
	int mid = (low + high) / 2;
	if (low <= high) {
		if (a[mid] = mid) {
			cout << "����a[i]=iҪ���Ԫ�أ�";
			cout << "a[" << mid << "]=" << mid << endl;
		}
		else if (a[mid] > mid)
			searchI(a, low, mid - 1);
		else if (a[mid] < mid)
			searchI(a, mid + 1, high);
	}
	else
		cout << "��������û�з���Ҫ���Ԫ��" << endl;
}

int main() {
	int n;
	cout << "�����������е�Ԫ�ظ�����";
	cin >> n;
	cout << "�밴�մ�С�����˳�����������е�Ԫ�أ�����Ԫ�ػ�����ȣ�:" << endl;
	int a[50];
	for (int k = 0; k < n; k++) {
		cin >> a[k];
	}
	cout << endl;
	
	searchI(a, 0, n - 1);
	return 0;
}