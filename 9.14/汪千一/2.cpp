#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution2 {
private:
    vector<int>arr;//输入的数组
    vector<int> B;//保存处理好的元素
    int mid;//保存中间元素
public:
    void reverse(vector<int>& arr) {
        int num = 0;//选择次数
        while (!arr.empty()) {//偶数个数据
            int len = arr.size();
            if (len == 1) {
                mid = arr[0];//奇数个数据
                break;
            }
            //首尾相等
            if (arr[0] == arr[len - 1]) {
                B.push_back(arr[0]);
                arr.erase(arr.begin());
                arr.erase(arr.end() - 1);
            }//开头两个数相加
            else if (arr[0] < arr[len - 1]) {
                arr[1] = arr[0] + arr[1];
                arr.erase(arr.begin());
                num++;
            }//末尾两个数相加
            else {
                arr[len - 2] = arr[len - 2] + arr[len - 1];
                arr.erase(arr.end() - 1);
                num++;
            }
        }
        cout << "选择次数：" << num << endl;
        return;
    }

    void print() {
        cout << "最终数列状态：";
        int i;
        for (i = 0; i < B.size(); i++) {
            cout << B[i]<<" ";
        }
        cout << mid<<" ";
        for (i = B.size() - 1; i >= 0; i--) {
            cout << B[i] <<" ";
        }

        return;
    }
};
int main() {
    cout << "第二题：" << endl;
    Solution2 s2;
    vector<int> arr;//输入的数组
    int n;//数组元素个数
    int t;//数组元素
    cout << "请输入数组元素个数：" ;
    cin >> n;
    cout << "请输入数组元素：";
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        arr.push_back(t);
    }
    s2.reverse(arr);
    s2.print();
}
