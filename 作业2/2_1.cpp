/**#include<iostream>
using namespace std;

void Simple(int a[], int low, int high) {
	//��ѡ������
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
	//����Ϊ������
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
	cout << "������Ҫ���������Ԫ�ظ�����";
	cin >> n;
	int a[50];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	SimpleSort(a, 0, n - 1);
	cout << "��С������������";
	for (int j = 0; j < n; j++) {
		cout << a[j] << " ";
	}
	cout << endl;
	return 0;
}*/