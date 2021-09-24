#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int> arr)
{
    int num = 0;
    int i = 0, j = arr.size() - 1;//从两头比较
    while (i < j)
    {
        if(arr[i] == arr[j])
        {
            i++; j--;
        }
        else if (arr[i] > arr[j])
        {
            j--; num += 1;
            arr[j] += arr[j+1];
            arr[j+1] = -1;
        }
        else if (arr[i] < arr[j])
        {
            i++; num += 1;
            arr[i] += arr[i-1];
            arr[i-1] = -1;
        }
    }
    cout<< "nums: "<< num<< endl;


    for(int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != -1) //筛去等于-1的
        cout<< arr[i]<< " ";
    }        
    cout<< endl;    
    
}

int main()
{
    // int arr[13] = {6, 3, 2, 1, 12, 32, 11, 23, 65, 18, 22, 10, 11};
    // vector<int> A(arr, arr+13);
    int arr[9] = {32, 11, 3, 1, 2, 3, 4, 6, 32};
    vector<int> A(arr, arr+9);
    solve(A);
    system("pause");
}