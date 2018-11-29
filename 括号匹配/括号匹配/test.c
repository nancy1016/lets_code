#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#define N 3
typedef char SDataType;
//动态栈
typedef struct Stack
{
	SDataType*_array;
	int _capacity;//有效元素的最大个数
	int _top;//栈顶
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
	//若空间已满，则进行扩容
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
//压栈（在栈顶插入数据data)
void StackPush(Stack*ps, SDataType data)
{
	assert(ps);
	_Checkcapacity(ps);
	ps->_array[ps->_top] = data;
	ps->_top++;
}



//检测栈是否为空(为空返回1，不为空返回0）
int StackEmpty(Stack*ps)
{
	assert(ps);
	return ps->_top == 0;
}



//出栈（在栈顶弹出数据data）
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


//取栈顶元素
SDataType StackTop(Stack*ps)
{
	assert(ps);
	//若栈为空
	assert(!StackEmpty(ps));
	//栈不为空
	return ps->_array[ps->_top - 1];
}

//获取栈中有效元素的个数
int StackSize(Stack*ps)
{
	assert(ps);
	return ps->_top;
}









//销毁栈
void StackDeatory(Stack*ps)
{
	assert(ps);
	free(ps->_array);
	ps->_top = 0;
}
//打印
void StackPrint(Stack*ps)
{
	assert(ps);
	for (int i = 0; i < ps->_top; i++)
	{
		printf("%d ", ps->_array[i]);
	}
	printf("\n");
}

//思路：逐一遍历字符串的括号
//1.如果是左括号，则入栈
//2.如果是右括号，检查是否与栈顶的左括号匹配
//注意：遇到后括号，不能急着取栈顶元素，一定要先检测栈是否为空，因为可能出现()]，这是不匹配的
//1)若匹配，则出栈，然后继续遍历字符串
//2)若不匹配，则直接返回false（没有必要再比较了）
int  isValid(char* s)
{
	Stack st;
	assert(s);
	StackInit(&st);
	int len = strlen(s);
	//逐一遍历字符串的括号
	for (int i = 0; i < len; i++)
	{
		//1.如果是左括号，则入栈
		if (s[i] == '(' || s[i] == '{' || s[i] == '[')
		{
			StackPush(&st, s[i]);
		}
		//如果是右括号
		else 
		{
			//先要判断栈是否为空，因为可能出现前边都已经匹配成功，只剩右括号的情况，如()]
			if (StackEmpty(&st))
			{
				return 0;
			}
			//在栈不为空的条件下继续判断是否匹配
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
	//走到这里说明字符串全部遍历完毕，若栈为空则说明是有效的字符串
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