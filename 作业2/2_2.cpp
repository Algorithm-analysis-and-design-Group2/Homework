/*#include<iostream>
using namespace std;

int calcu(int x, int n) {

	int temp;
	if (n == 1) {
		return x;
	}
	else {
		if (n % 2 == 0) {//�����nΪż��
			temp = calcu(x, n / 2);
			return temp * temp;
		}
		else {//�����nΪ����
			temp = calcu(x, (n - 1) / 2);
			return x * temp * temp;
		}
	}
}
int main() {
	int x, n;
	cout << "���x��n�η���" << endl;
	cout << "������x��";
	cin >> x;
	cout << "������n��";
	cin >> n;
	int result = calcu(x, n);
	cout << "���Ϊ��" << result << endl;
	return 0;
}*/