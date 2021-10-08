// 作业二.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
/*
作业二：

1、请用分治法实现简单选择排序，并分析算法复杂度。

2、设计一个算法，采用分治法求 xn

3、设计一个尽可能高效的算法，输出给定长度为n的整数数列中出现次数超过一半的元素。

4、设有 n 个互不相同的整数，按递增顺序存放在数组 a[0..n-1]中，
若存在一个下标i（0≤i<n），使得 a[i]==b。采用分治法以 O(logn)时间找到这个下标 i。*/

#include <iostream>
#include <vector>
using namespace std;
int count_1 = 0;
int count_2 = 0;
int count_3 = 0;
int count_4 = 0;
int A[16] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };
vector<int>B;
int f(vector<int>BR, int m) {//找出第m元素后的最小元素的下标
	count_1++;
	if (m == BR.size()-1) { return m; }
	else {
		int temp = f(BR, m + 1);
		if (BR[temp] < BR[m]) {
			return temp;
		}
		else {
			return m;
		}
	}
}
int power(int x, int m) {
	count_2++;
	int y = -1;
	if (m == 0) y = 1;
	else {
		y = power(x, m / 2);
		y = y * y;
		if (m % 2 == 1) { y = x * y; }
	}
	return y;
}
int candidate(int m,int n) {
	count_3++;
	int j = m;
	int c = A[m];
	int count = 1;
	while (j < n and count>0) {
		j = j + 1;
		if (A[j] == c)
		{
			count = count + 1;
		}
		else {
			count = count - 1;
		}
	}if (j == n) return c;       //获取候选者    
	else return candidate(j + 1,n);
	
}
int binarysearch(int b, int low, int high) {
/*设有 n 个互不相同的整数，按递增顺序存放在数组 a[0..n - 1]中，
若存在一个下标i（0≤i < n），使得 a[i] == b。采用分治法以 O(logn)时间找到这个下标 i */
	count_4++;
	int mid = (low + high) / 2;
	if (A[mid] == b) return mid;
	else if (A[mid] > b)
	{
		int l = binarysearch(b, low, mid);
		if (A[l] == b) return l;
		else return -1;
	}
	else {
		int h = binarysearch(b, mid + 1, high);
		if (A[h] == b) return h;
		else return -1;
	}
}
void pm_01(){
	for (int i = 0; i < 16; i++)
	{
		B.push_back(A[i]);
	}
	for (int i = 0; i < 16; i++)
	{
		int mim=f(B, 0);//得到最小元素下标
		cout <<i<<","<< mim << ",";
		cout<< B[mim] << endl;
		B.erase(B.begin()+mim);//删除该下标元素
	}
	cout << endl<<"运行次数是:"<< count_1 << endl;
}
void pm_02() {
	cout << "4的3次方是:" << power(4, 3) << endl;
	cout<<"运行次数是:"<<count_2 << endl;
}
void pm_03() {
	int n = 10;
	int c = candidate(1, n);
	int count = 0;
	for (int j = 1; j < n; j++) {
		if (A[j] == c) count = count + 1;  //候选者进行计数
	}
	if (count > n / 2)cout << c; 
	else cout<<"没有多数元素！" <<endl;
	cout<< "运行次数是:" << count_3<<endl;
}
void pm_04() {
	cout<<"下标是:"<<binarysearch(1, 0, 9)<<endl;
	cout <<"运行次数是:"<<count_4<<endl;
}

int main()
{
	int choice = -1;
	while (true) {
		cout << "输入数字进入对应题目:";
		cin >> choice;
		switch (choice) {
		case 1: pm_01(); break;//O(n^2) 
		case 2: pm_02(); break;//Θ(logn)
		case 3: pm_03(); break;//O(n)
		case 4: pm_04(); break;//O(logn)
		default:cout << "输入不合法，退出程序！"; return 0;
		}
	}
}