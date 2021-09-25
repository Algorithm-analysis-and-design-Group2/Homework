#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution3 {
private:
    int min;//记录目前股价最低的一天
    int profit;//股价相差最大的两天
    int buy;//买入的日期
    int sell;//卖出的日期
public:
    void calculate(vector<int>& arr) {
        min = arr[0];
        profit = arr[1] - arr[0];
        for (int i = 0; i < arr.size(); i++) {
            //买入
            if (min > arr[i]) {
                min = arr[i];
                buy=i+1;//买入的日期
            }
            //卖出
            if (profit < arr[i] - min) {
                profit = arr[i] - min;
                sell = i+1;//卖出的日期
            }
        }
        cout << "买入日期：" << buy << endl;
        cout << "卖出日期：" << sell << endl;
        cout <<"所得收益："<<profit*1000;
        return;
    }
};
int main ()
{
    Solution3 s3;
    int n;//交易日天数
    int t;//每个交易日的股价
    vector<int> A;
    cout << "请输入交易日天数：" << endl;
    cin >> n;
    cout << "请输入每个交易日的股价：" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "第" << i + 1 << "天：";
        cin >> t;
        A.push_back(t);
    }
    s3.calculate(A);

}