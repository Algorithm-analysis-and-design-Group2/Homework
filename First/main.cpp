#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int max(int a, int b);
void printVector(vector<int> vect);

vector<int>combinitionSum(vector<int>A , int target)
{

	//1.׼��

	int n = A.size();
	vector<int> newVector;

	//ÿһ��ֵ����ӦA�е�һ��Ԫ��
	vector<int>value;
	vector<int>weight;

	//��Ϊdp[][]�ĵ�һ�е�һ�ж��Ƚ����⣬���ԣ�value[0]=0��weight[0]=0
	//����value��Ԫ��ֵΪ1��weight������Ԫ����A��Ӧ
	value.push_back(0);
	weight.push_back(0);
	for (int i = 0; i <n; i++)
	{
		value.push_back(1);
		weight.push_back(A[i]);
	}

	
	
	//��Ϊ���ᴴ��dp[n+1][target],���Ծ͸ɴ���һ�����

	//2.dp��ʼֵ����Ϊ��ǡ��װ�������Ե�һ��Ϊ0��������ȫ����ʼ��Ϊ-999
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

	//3.������û����͸��)
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
	//4.���ݱ��ó�ѡ������Щ���֣�����push��newVector�У�Ȼ�󷵻�newVector��
	while (target > 0)
	{
		int tempi = -1;
		int k = 0;
		for (int i = 0; i <= n; i++)
		{
			if (dp[i][target] < 0)//����ǡ��װ��
			{

			}
			else//����װ��������Ҫ�Д��ǲ������
			{
				if (dp[i][target] > tempi)
				{
					k = i;
					tempi = dp[i][target];
				}
			}
			//�Д��Л]�а�ĳһ�з�0��v�꣬��v���Ԓ�Ͱ��@���x�еĔ����Mȥ��Ȼ��break,
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