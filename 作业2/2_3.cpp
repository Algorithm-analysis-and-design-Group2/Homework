/**#include<iostream>
using namespace std;

int Partition(int a[], int low, int high) //��a[low]Ϊ��׼����
{
    int i = low, j = high;
    int povit = a[low];
    while (i < j)
    {
        while (i < j && a[j] >= povit)
            j--;
        a[i] = a[j];
        while (i < j && a[i] <= povit)
            i++;
        a[j] = a[i];
    }
    a[i] = povit;
    return i;
}

void solve(int a[], int n) {
    int mid = n / 2;
    int low = 0; int high = n - 1;
    bool flag = true;
    int mark, count = 0;
    while (flag) {
        int i = Partition(a, low, high);
        if (i == mid) {
            mark = i;
            flag = false;
        }
        else if (i > mid) {
            high = i - 1;
        }
        else {
            low = i + 1;
        }
    }
    for (int k = 0; k < n; k++) {
        if (a[k] == a[mark]) {
            count++;
        }
    }
    if (count > n / 2) {
        cout << "�������г��ִ�������һ���Ԫ��Ϊ��" << a[mark] << endl;
    }
    else {
        cout << "��������û�г��ִ�������һ���Ԫ��" << endl;
    }
}

int main() {

	int n;
	cout << "������������Ԫ�صĸ�����";
	cin >> n;
    int a[50];
    cout << "�����������е�Ԫ�أ�";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    solve(a, n);
    return 0;
}*/