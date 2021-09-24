#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;//集合中元素的个数
int sum;//要求的和
int flag[100];//标记集合中被选中元素的索引
int result = 0;//记录找到结果数，为0表示无解
int temp = 0;
int A[100];//要输入的集合

void findPass(int i) 
{
    if (i > n) //要找的第i个数序号比个数大，返回
    {
        return;
    }
    else 
    {
        temp = temp + A[i];//累加和
        flag[i] = 1;//把该元素标记为1

        if (sum == temp) //如果和为sum，则把标记为1的元素输出
        {
            for(int j = 0; j < n; j++) 
            {
                if(flag[j] == 1) 
                {
                    printf("%d ", A[j]);
                }
            }
            printf("\n");
            result++;//result为1，有解
            exit(0);
        }
        else if (temp < sum)//如果和小于sum，就递归进行搜索
        {
            findPass(i+1);
        }
        else//如果和大于sum，则去除这一步的搜索，对下一个元素进行计算
        {
            temp -= A[i];
            flag[i] = 0;
            findPass(i+1);
            return;
        }
    }
}

int main(void) {

    scanf("%d", &n);

    for(int i = 0; i < n; i++) 
    {
        scanf("%d", &A[i]);
    }

    scanf("%d", &sum);

    for(int i = 0; i < n; i++) 
    {
        memset(flag, 0, sizeof(flag));
        temp = 0;
        findPass(i);
    }
    if (result == 0) 
    {
        printf("No Solution!\n");
    }
    return 0;
    system("pause");
}