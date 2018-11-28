#include<stdio.h>
#include<stdlib.h>

void Find_Two_MaxNum(int a[], int size, int*max,int *second)
{
	//第一步:先找出前两个中较大数和较小数，分别赋值给*max和*second
	*max = a[0];
	*second = a[0];
	if (a[0] > a[1])
	{
		*second = a[1];
	}
	else
	{
		*max = a[1];
	}
	//第二步：遍历数组，更新值
	for (int i = 1; i < size; i++)
	{
		if (a[i]>*max)//如果当前值大于*max，直接更新*max
		{
			*max = a[i];
		}
		else if(a[i]<*max&&a[i]>*second)//如果当前值小于*max，则要判断它与*second的大小来确定要不要更新*second
		{
			*second = a[i];		
		}
	}
}
int main()
{
	int arr[] = { 1,9,4,3,2 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int _max = 0;
	int _second =0;
	Find_Two_MaxNum(arr, size, &_max, &_second);
	printf("最大的数字为：%d\n", _max);
	printf("第二大的数字为：%d\n", _second);
	system("pause");
	return 0;
}