#include<iostream>
using namespace std;

int Question3(int data[], int num, int startDate, int& buyDate, int& sellDate) {
	int biggest = startDate, smallest = startDate;
	for (int i = startDate; i < num; i++)
		if (data[i] > data[biggest]) biggest = i;
	for (int i = startDate; i < biggest + 1; i++)
		if (data[i] < data[smallest]) smallest = i;
	buyDate = smallest;
	sellDate = biggest;

	int bestBeforeBiggest = data[biggest] - data[smallest];
	int bestAfterBiggest;
	if(biggest < num - 1)
	bestAfterBiggest = Question3(data, num, biggest + 1, buyDate, sellDate);
	else bestAfterBiggest = 0;

	if (bestBeforeBiggest >= bestAfterBiggest) {
		buyDate = smallest;
		sellDate = biggest;
		return bestBeforeBiggest;
	}
	else return bestAfterBiggest;
}

int main() {
	int A[] = { 1755,1749,1724,1699,1671,1693,1799,1750,1690,1700,
				   1699,1635,1620,1619,1548,1570,1625,1665,1595,1596,
				   1586,1558,1622,1618,1658,1670,1669,1633,1634,1662};
	int buyDate = 0, sellDate = 0;
	printf("Profits:%d\n",Question3(A, 30, 0, buyDate, sellDate));
	printf("Buy Date:%d, Sell Date:%d", buyDate+1, sellDate+1);
	return 0;
}