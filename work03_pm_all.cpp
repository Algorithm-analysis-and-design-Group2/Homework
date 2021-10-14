// 作业三.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//本周作业：上机实现求解LCS的动态规划算法，最长公共子序列

//如:输入两个字符串A和B，输出A相对于B的重复率，
//并标记出字符串A中相对于B串的LCS


#include <iostream>;
using namespace std;
#include <vector>;
int L[100][100] = {};
char A[100] = {};
char B[100] = {};
string same="";
vector<char> subs;
int LCS(int n ,int m) {
    for (int i = 0; i < n+1; i++) {
        L[i][0] = 0;
    }
    for (int j = 0; j < m+1; j++) {
        L[0][j] = 0;
    }
    for (int i = 1; i < n+1; i++) {
        for (int j = 1; j < m+1; j++) {
            if (A[i-1] == B[j-1]) {
                L[i][j] = L[i-1][j- 1] + 1;
            }
            else {
                L[i][j] = max(L[i][j -1],L[i - 1][j]);
            }
        }

    }
    for (int i = 0; i < n+1; i++) {
        for (int j = 0; j < m+1 ; j++) {
            cout << L[i][j] << "\t";
        }
        cout << "\n";
    }
    return L[n][m];
}
//xyxxzxyzxy
//zxzyyzxxyxxz
void Buildsubs(int n, int m,int k)		    //由dp构造从subs
{
    int i = n;
    int j = m;
    while (k > 0)			    //在subs中放入最长公共子序列(反向)
    {
        if (L[i][j] == L[i - 1][j])
            i--;
        else if (L[i][j] == L[i][j - 1])
            j--;
        else			    //与上方、左边元素值均不相等
        {
            subs.push_back(A[i - 1]);  //subs中添加a[i-1]
            i--; j--; k--;
        }
    }
    cout << "最长公共子序列：";
    int num = subs.size();
    for (int i = num-1; i>=0; i--) {
        cout << subs[i] << "  ";
    }
    cout << endl;
}
int main()
{
    /*string a = "";
    string b = ""; */
    string a = "xyxxzxyzxy";
    string b = "zxzyyzxxyxxz";
   /* cin >> a;
    cin >> b;*/
    int n =a.size();
    int m =b.size();
    for (int i = 0; i < n; i++) {
        A[i] = a[i];
    }
    for (int j = 0; j < m; j++) {
        B[j] = b[j];
    }
    int samelength = LCS(n, m);
    Buildsubs(n, m,samelength);
    cout << endl << "子序列长度：" << samelength << endl;
    cout << "A的长度：" << n<<endl<<"B的长度：" << m<<endl;
    double slength = samelength;
    double msize = m;
    double samepercent = slength / msize;
    cout << "A相对B的重复率：" << samepercent;

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
