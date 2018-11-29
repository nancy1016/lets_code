#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#define N 3
typedef char SDataType;
//��̬ջ
typedef struct Stack
{
	SDataType*_array;
	int _capacity;//��ЧԪ�ص�������
	int _top;//ջ��
}Stack;

//Stack st;
void StackInit(Stack*ps)
{
	assert(ps);
	ps->_array = (SDataType*)malloc(sizeof(SDataType)*N);
	if (ps->_array == NULL)
	{
		exit(1);
	}
	ps->_capacity = N;
	ps->_top = 0;
}

void _Checkcapacity(Stack*ps)
{
	//���ռ����������������
	if (ps->_top == ps->_capacity)
	{
		int New_capacity = ps->_capacity * 2;
		ps->_array = (SDataType*)realloc(ps->_array, sizeof(SDataType)*New_capacity);
		if (ps->_array == NULL)
		{
			exit(1);
		}
		ps->_capacity = New_capacity;
	}
}
//ѹջ����ջ����������data)
void StackPush(Stack*ps, SDataType data)
{
	assert(ps);
	_Checkcapacity(ps);
	ps->_array[ps->_top] = data;
	ps->_top++;
}



//���ջ�Ƿ�Ϊ��(Ϊ�շ���1����Ϊ�շ���0��
int StackEmpty(Stack*ps)
{
	assert(ps);
	return ps->_top == 0;
}



//��ջ����ջ����������data��
void StackPop(Stack*ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	/*if (ps->_top == 0)
	{
	return;
	}*/
	ps->_top--;
}


//ȡջ��Ԫ��
SDataType StackTop(Stack*ps)
{
	assert(ps);
	//��ջΪ��
	assert(!StackEmpty(ps));
	//ջ��Ϊ��
	return ps->_array[ps->_top - 1];
}

//��ȡջ����ЧԪ�صĸ���
int StackSize(Stack*ps)
{
	assert(ps);
	return ps->_top;
}









//����ջ
void StackDeatory(Stack*ps)
{
	assert(ps);
	free(ps->_array);
	ps->_top = 0;
}
//��ӡ
void StackPrint(Stack*ps)
{
	assert(ps);
	for (int i = 0; i < ps->_top; i++)
	{
		printf("%d ", ps->_array[i]);
	}
	printf("\n");
}

//˼·����һ�����ַ���������
//1.����������ţ�����ջ
//2.����������ţ�����Ƿ���ջ����������ƥ��
//ע�⣺���������ţ����ܼ���ȡջ��Ԫ�أ�һ��Ҫ�ȼ��ջ�Ƿ�Ϊ�գ���Ϊ���ܳ���()]�����ǲ�ƥ���
//1)��ƥ�䣬���ջ��Ȼ����������ַ���
//2)����ƥ�䣬��ֱ�ӷ���false��û�б�Ҫ�ٱȽ��ˣ�
int  isValid(char* s)
{
	Stack st;
	assert(s);
	StackInit(&st);
	int len = strlen(s);
	//��һ�����ַ���������
	for (int i = 0; i < len; i++)
	{
		//1.����������ţ�����ջ
		if (s[i] == '(' || s[i] == '{' || s[i] == '[')
		{
			StackPush(&st, s[i]);
		}
		//�����������
		else 
		{
			//��Ҫ�ж�ջ�Ƿ�Ϊ�գ���Ϊ���ܳ���ǰ�߶��Ѿ�ƥ��ɹ���ֻʣ�����ŵ��������()]
			if (StackEmpty(&st))
			{
				return 0;
			}
			//��ջ��Ϊ�յ������¼����ж��Ƿ�ƥ��
			char ch = StackTop(&st);
			if ((ch == '['&&s[i] == ']') ||
				(ch == '{'&&s[i] == '}') ||
				(ch == '('&&s[i] == ')'))
			{
				StackPop(&st);
			}
			else
			{
				return 0;
			}	
		}
	}
	//�ߵ�����˵���ַ���ȫ��������ϣ���ջΪ����˵������Ч���ַ���
	if (StackEmpty(&st))
	{
		return 1;
	}
	return 0;
}




int main()
{
	/*Stack st;
	char*s = "()[]{}";
	StackInit(&st);*/

	char*s = "[]}";
	int ret = isValid(s);

	//int ret = StackEmpty(&st);
	printf("ret=%d", ret);
	system("pause");
	return 0;
}