#include <iostream>
#include <vector>;
using namespace std;
int n;
int sum;
int A[1024] = {  };
vector<int> tmppath;
vector<int> path;	
int coun = 0;
void f(int A[], int i, int sum, vector<int> tmppath, vector<int>& path) {
	coun++;
	if (i == n) {//必定结束，如果sum==0，且此时的tmppath大，那么替换
		if (sum == 0&& tmppath.size() > path.size()) {
				path = tmppath;
		}
		return;
	}
	else {
		//结束有两种情况，一种是当前是元素个数为n的集合，一种是sum<0
		//判断一下，sum = 0则继续，
		//如果i已经到n了说明已经选了n个，如果还大于的话就false
		if (sum < 0) {//在选择时，如果让sum<0，
			//那就直接false，sum=0
			return;
		}

		else if (sum == 0) {
			if (tmppath.size() > path.size()) {
				path = tmppath;
			}
			return ;
		}

		else {
			for (int k = i; k < n; k++) {//则从A[0]到A[n-1]选
				//if(A[k])
				tmppath.push_back(A[k]);
				f(A, k + 1, sum - A[k], tmppath, path);
				tmppath.pop_back();
			}
		}
	}
}
void BubbleSort(int A[],int n,int i)
{
	int  j;
	bool exchange;
	if (i == n - 1) return;		//满足递归出口条件
	else
	{
		exchange = false;		//置exchange为false
		for (j = n - 1; j > i; j--)
			if (A[j] < A[j - 1])		//当相邻元素反序时
			{
				swap(A[j], A[j - 1]);
				exchange = true;	//发生交换置exchange为true
			}
		if (exchange == false)		//未发生交换时直接返回　　　
			return;
		else				//发生交换时继续递归调用
			BubbleSort(A,n,i + 1);
	}
}

void makearray() {
	cout << "输入n:";
	cin >> n;
	cout << "输入sum:";
	cin >> sum;
	for (int i = 0; i < n; i++) {
		int tmpt;
		cout << "输入A[" << i << "]:";
		cin >> tmpt;
		A[i] = tmpt;
	}
}
int main()
{
	makearray();
	BubbleSort(A, n, 0);
	for (int i = 0; i < n; i++) 
	{
		cout << A[i]<<"   ";
	}
	f(A, 0, sum, tmppath, path);
	cout << "S的基数：" << path.size() << endl<<"S的元素：";
	for (int i = 0; i < path.size(); i++) 
	{
		cout << path[i] << "   ";
	}
	cout << "运行次数：" << coun;
}
