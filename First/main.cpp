#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int max(int a, int b);
void printVector(vector<int> vect);

vector<int>combinitionSum(vector<int>A , int target)
{

	//1.准备

	int n = A.size();
	vector<int> newVector;

	//每一对值，对应A中的一个元素
	vector<int>value;
	vector<int>weight;

	//因为dp[][]的第一行第一列都比较特殊，所以，value[0]=0；weight[0]=0
	//其他value的元素值为1，weight的其他元素与A对应
	value.push_back(0);
	weight.push_back(0);
	for (int i = 0; i <n; i++)
	{
		value.push_back(1);
		weight.push_back(A[i]);
	}

	
	
	//因为不会创建dp[n+1][target],所以就干脆搞大一点好了

	//2.dp初始值，因为是恰好装满，所以第一列为0，其他列全部初始化为-999
	int dp[15][150];
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 150; j++)
		{
			if (j == 0)
			{
				dp[i][j] = 0;
			}
			else
			{
				dp[i][j] = -999;
			}

		}
	}

	//3.填表（这段没理解很透彻)
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= target; j++)
		{
			if (j >= weight[i])
			{
				dp[i][j] = max(dp[i - 1][j],dp[i - 1][j - weight[i]] + value[i]);
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	//4.根据表，得出选择了那些数字，并且push到newVector中，然后返回newVector。
	while (target > 0)
	{
		int tempi = -1;
		int k = 0;
		for (int i = 0; i <= n; i++)
		{
			if (dp[i][target] < 0)//不能恰好装满
			{

			}
			else//可以装满，但是要判斷是不是最好
			{
				if (dp[i][target] > tempi)
				{
					k = i;
					tempi = dp[i][target];
				}
			}
			//判斷有沒有把某一列非0遍歷完，遍歷完的話就把這個選中的數放進去，然後break,
			if (i == n)
			{
				newVector.push_back(weight[k]);
				//cout << "newVector.pushback" << weight[k] << endl;
				target -= weight[k];
				break;
			}
		}
	}
	//5.return
	return newVector;
}

int main()
{
	vector<int>A = { 3,2,5,7,8,9,6,10,14 };
	vector<int>toBeReturn = combinitionSum(A, 16);
	printVector(toBeReturn);

	system("pause");
	return 0;
}
int max(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
void printVector(vector<int> vect)
{
	cout << endl;
	for (vector<int>::iterator it = vect.begin(); it != vect.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}