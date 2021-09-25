#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution1 {

private:
    vector<int> A;//输入的数据
    int target;//目标结果
    vector<vector<int>> res;//所有组合
    vector<int> path;//一种组合
public:
    void DFS(int start, int target) {
        if (target == 0) {
            res.push_back(path);//找到的所有组合
            return;
        }

        for (int i = start; i < A.size() && target - A[i] >= 0; i++) {
            path.push_back(A[i]);//找到满足条件所有的点            
            DFS(i + 1, target - A[i]);
            path.pop_back();
        }
    }

    vector<vector<int>> combSum(vector<int>& A, int target) {
        this->A = A;
        DFS(0, target);//从第一个数开始遍历
        return res;
    }

    void print() {
        int num, i, t;
        t = 0;
        num = res[0].size();//所有组合的元素个数
        for (i = 1; i < res.size(); i++) {
            if (num < res[i].size())
                num = res[i].size(), t = i;   //找到元素个数最多的组合       
        }
        cout << "集合中的元素：";
        for (i = 0; i < num; i++) {
            cout << res[t][i]<<" ";
        }
        cout << "\n基数：" << num;
    }
};
int main() {
    cout << "第一题：" << endl;
    Solution1 s1;
    vector<int> A;//输入的数组
    int n;//数组元素个数
    int t;//数组元素
    int sum;//目标结果
    cout << "请输入数组元素个数：" ;
    cin >> n;
    cout << "请输入数组元素：" ;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        A.push_back(t);
    }
    cout << "请输入目标结果：" ;
    cin >> sum;
    s1.combSum(A, sum);
    s1.print();
}