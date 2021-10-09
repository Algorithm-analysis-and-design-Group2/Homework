/*#include<iostream>
using namespace std;

int calcu(int x, int n) {

	int temp;
	if (n == 1) {
		return x;
	}
	else {
		if (n % 2 == 0) {//输入的n为偶数
			temp = calcu(x, n / 2);
			return temp * temp;
		}
		else {//输入的n为奇数
			temp = calcu(x, (n - 1) / 2);
			return x * temp * temp;
		}
	}
}
int main() {
	int x, n;
	cout << "求解x的n次方：" << endl;
	cout << "请输入x：";
	cin >> x;
	cout << "请输入n：";
	cin >> n;
	int result = calcu(x, n);
	cout << "结果为：" << result << endl;
	return 0;
}*/