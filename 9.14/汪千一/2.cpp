#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution2 {
private:
    vector<int>arr;//���������
    vector<int> B;//���洦��õ�Ԫ��
    int mid;//�����м�Ԫ��
public:
    void reverse(vector<int>& arr) {
        int num = 0;//ѡ�����
        while (!arr.empty()) {//ż��������
            int len = arr.size();
            if (len == 1) {
                mid = arr[0];//����������
                break;
            }
            //��β���
            if (arr[0] == arr[len - 1]) {
                B.push_back(arr[0]);
                arr.erase(arr.begin());
                arr.erase(arr.end() - 1);
            }//��ͷ���������
            else if (arr[0] < arr[len - 1]) {
                arr[1] = arr[0] + arr[1];
                arr.erase(arr.begin());
                num++;
            }//ĩβ���������
            else {
                arr[len - 2] = arr[len - 2] + arr[len - 1];
                arr.erase(arr.end() - 1);
                num++;
            }
        }
        cout << "ѡ�������" << num << endl;
        return;
    }

    void print() {
        cout << "��������״̬��";
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
    cout << "�ڶ��⣺" << endl;
    Solution2 s2;
    vector<int> arr;//���������
    int n;//����Ԫ�ظ���
    int t;//����Ԫ��
    cout << "����������Ԫ�ظ�����" ;
    cin >> n;
    cout << "����������Ԫ�أ�";
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        arr.push_back(t);
    }
    s2.reverse(arr);
    s2.print();
}
