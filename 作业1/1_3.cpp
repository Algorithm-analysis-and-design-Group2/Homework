#include <iostream>
using namespace std;

int A[] = { 1755,1749,1724,1699,1671,1693,1799,1750,1690,1700,1699,1635,1620,1619,1548,1570,1625,1665,1595,1596,1585,1558,1622,1618,1658,1670,1669,1633,1634,1662 };
int incomes[30];
int date[30];
int rs;

void solve(int n) {
	if (n > 29) {
		incomes[29] = 0;
	}
	else {
		int income = 0;
		for (int i = n + 1; i < 30; i++) {
			int sub = A[i] - A[n];
			if (income < sub) {
				income = A[i] - A[n];
				incomes[n] = income;
				date[n] = i + 1;
			}
		}
		solve(n + 1);
	}
}

int main() {
	int income = 0;
	int i, monthin, monthout;
	solve(0);
	for (i = 0; i < 30; i++) {
		if (income < incomes[i]) {
			income = incomes[i];
			monthin = i + 1;
			monthout = date[i];
			
		}
	}
	cout << monthin << "月买入，" << monthout << "月卖出收益最大" << endl;
	cout << "总收益为：" << income << endl;

	return 0;
}