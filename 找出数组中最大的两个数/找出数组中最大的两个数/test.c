#include<stdio.h>
#include<stdlib.h>

void Find_Two_MaxNum(int a[], int size, int*max,int *second)
{
	//��һ��:���ҳ�ǰ�����нϴ����ͽ�С�����ֱ�ֵ��*max��*second
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
	//�ڶ������������飬����ֵ
	for (int i = 1; i < size; i++)
	{
		if (a[i]>*max)//�����ǰֵ����*max��ֱ�Ӹ���*max
		{
			*max = a[i];
		}
		else if(a[i]<*max&&a[i]>*second)//�����ǰֵС��*max����Ҫ�ж�����*second�Ĵ�С��ȷ��Ҫ��Ҫ����*second
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
	printf("��������Ϊ��%d\n", _max);
	printf("�ڶ��������Ϊ��%d\n", _second);
	system("pause");
	return 0;
}