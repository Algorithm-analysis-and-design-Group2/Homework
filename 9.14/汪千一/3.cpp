#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution3 {
private:
    int min;//��¼Ŀǰ�ɼ���͵�һ��
    int profit;//�ɼ������������
    int buy;//���������
    int sell;//����������
public:
    void calculate(vector<int>& arr) {
        min = arr[0];
        profit = arr[1] - arr[0];
        for (int i = 0; i < arr.size(); i++) {
            //����
            if (min > arr[i]) {
                min = arr[i];
                buy=i+1;//���������
            }
            //����
            if (profit < arr[i] - min) {
                profit = arr[i] - min;
                sell = i+1;//����������
            }
        }
        cout << "�������ڣ�" << buy << endl;
        cout << "�������ڣ�" << sell << endl;
        cout <<"�������棺"<<profit*1000;
        return;
    }
};
int main ()
{
    Solution3 s3;
    int n;//����������
    int t;//ÿ�������յĹɼ�
    vector<int> A;
    cout << "�����뽻����������" << endl;
    cin >> n;
    cout << "������ÿ�������յĹɼۣ�" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "��" << i + 1 << "�죺";
        cin >> t;
        A.push_back(t);
    }
    s3.calculate(A);

}