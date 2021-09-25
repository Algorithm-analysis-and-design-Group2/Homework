#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution1 {

private:
    vector<int> A;//���������
    int target;//Ŀ����
    vector<vector<int>> res;//�������
    vector<int> path;//һ�����
public:
    void DFS(int start, int target) {
        if (target == 0) {
            res.push_back(path);//�ҵ����������
            return;
        }

        for (int i = start; i < A.size() && target - A[i] >= 0; i++) {
            path.push_back(A[i]);//�ҵ������������еĵ�            
            DFS(i + 1, target - A[i]);
            path.pop_back();
        }
    }

    vector<vector<int>> combSum(vector<int>& A, int target) {
        this->A = A;
        DFS(0, target);//�ӵ�һ������ʼ����
        return res;
    }

    void print() {
        int num, i, t;
        t = 0;
        num = res[0].size();//������ϵ�Ԫ�ظ���
        for (i = 1; i < res.size(); i++) {
            if (num < res[i].size())
                num = res[i].size(), t = i;   //�ҵ�Ԫ�ظ����������       
        }
        cout << "�����е�Ԫ�أ�";
        for (i = 0; i < num; i++) {
            cout << res[t][i]<<" ";
        }
        cout << "\n������" << num;
    }
};
int main() {
    cout << "��һ�⣺" << endl;
    Solution1 s1;
    vector<int> A;//���������
    int n;//����Ԫ�ظ���
    int t;//����Ԫ��
    int sum;//Ŀ����
    cout << "����������Ԫ�ظ�����" ;
    cin >> n;
    cout << "����������Ԫ�أ�" ;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        A.push_back(t);
    }
    cout << "������Ŀ������" ;
    cin >> sum;
    s1.combSum(A, sum);
    s1.print();
}