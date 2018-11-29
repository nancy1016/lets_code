#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef struct Elem
{
	int _data;
	int _min;
}Elem;

typedef Elem SDataType;
//动态栈
typedef struct Stack
{
	SDataType*_array;
	int _capacity;//有效元素的最大个数
	int _top;//栈顶
}Stack;


//栈的初始化
void StackInit(Stack*ps,int capacity)
{
	assert(ps);
	ps->_array = (SDataType*)malloc(sizeof(SDataType)*capacity);
	if (ps->_array == NULL)
	{
		exit(1);
	}
	ps->_capacity = capacity;
	ps->_top = 0;
}

void _Checkcapacity(Stack*ps,int capacity)
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



//检测栈是否为空(为空返回1，不为空返回0）
int StackEmpty(Stack*ps)
{
	assert(ps);
	return ps->_top == 0;
}

//压栈（在栈顶插入数据data)
void StackPush(Stack*ps, SDataType data)
{
	assert(ps);
	_Checkcapacity(ps,3);
	ps->_array[ps->_top] = data;
	ps->_top++;
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
	ps->_capacity = 0;
	ps->_top = 0;
}

////////////////////////////////////////////////

typedef struct
{
	Stack _s;
} MinStack;



/** initialize your data structure here. */
MinStack* minStackCreate(int maxSize)
{
	//MinStack pms;
	//StackInit(&(pms._s), maxSize);

	MinStack*pms = (MinStack*)malloc(sizeof(MinStack));//?
	if (pms == NULL)
	{
		return NULL;
	}
	StackInit(&(pms->_s), maxSize);
	return pms;
}



int minStackGetMin(MinStack* obj)
{
	int min = StackTop(&(obj->_s))._min;
	return min;
}
void minStackPush(MinStack* obj, int x)
{
	Elem e;
	e._data = x;
	e._min = x;
	//
	if (!StackEmpty(&(obj->_s)))
	{
		int min = minStackGetMin(obj);
		if (x > minStackGetMin(obj))
		{
			e._min = min;
		}
	}
	StackPush(&(obj->_s), e);
}

void minStackPop(MinStack* obj)
{
	StackPop(&(obj->_s));
}

int minStackTop(MinStack* obj)
{
	int data = StackTop(&(obj->_s))._data;
	return data;
}



void minStackFree(MinStack* obj)
{
	StackDeatory(&(obj->_s));
	free(obj);
}

int main()
{
	MinStack* ms = minStackCreate(3);
	minStackPush(ms, 1);
	minStackPush(ms, 2);
}




////定义数组中的节点对结构
//typedef struct ELem
//{
//	int _data;
//	int _min;
//}ELem;
//
//typedef ELem SDataType;
//
////定义栈的结构
//typedef struct MinStack
//{
//	SDataType*_array;
//	int _capacity;//有效元素的最大个数
//	int _top;//栈顶
//}MinStack;
//
//
//
//
//void StackInit(MinStack*ps,int maxsize)
//{
//	assert(ps);
//	ps->_array = (SDataType*)malloc(sizeof(SDataType)*maxsize);
//	if (ps->_array == NULL)
//	{
//		exit(1);
//	}
//	ps->_capacity = maxsize;
//	ps->_top = 0;
//}
//
//
////压栈（在栈顶插入数据data)
//void StackPush(MinStack*ps, SDataType data)
//{
//	assert(ps);
//	_Checkcapacity(ps);
//	ps->_array[ps->_top] = data;
//	ps->_top++;
//}
//
//MinStack* minStackCreate(int maxSize)
//{
//	MinStack*ps;
//	StackInit(ps, maxSize);
//}
//
//
//void minStackPush(MinStack* obj, int x)
//{
//	ELem e;
//	e._data = x;
//	e._min = x;
//
//	
//}
//
//
//
//
//
//void _Checkcapacity(MinStack*ps)
//{
//	//若空间已满，则进行扩容
//	if (ps->_top == ps->_capacity)
//	{
//		int New_capacity = ps->_capacity * 2;
//		ps->_array = (SDataType*)realloc(ps->_array, sizeof(SDataType)*New_capacity);
//		if (ps->_array == NULL)
//		{
//			exit(1);
//		}
//		ps->_capacity = New_capacity;
//	}
//}
//
//
////压栈（在栈顶插入数据data)
//void StackPush(MinStack*ps, SDataType data)
//{
//	assert(ps);
//	_Checkcapacity(ps);
//	ps->_array[ps->_top] = data;
//	ps->_top++;
//}



//int main()
//{
//	MinStack st;
//
//	//Stack st;
//	
//	system("pause");
//	return 0;
//}







//void StackInit(Stack*ps)
//{
//	assert(ps);
//	ps->_array = (SDataType*)malloc(sizeof(SDataType)*N);
//	if (ps->_array == NULL)
//	{
//		exit(1);
//	}
//	ps->_capacity = N;
//	ps->_top = 0;
//}
///** initialize your data structure here. */
//MinStack* minStackCreate(int maxSize)
//{
//	MinStack*ms = (MinStack*)malloc(sizeof(MinStack));
//	
//}
//
//void minStackPush(MinStack* obj, int x)
//{
//
//}
//
//void minStackPop(MinStack* obj)
//{
//
//}
//
//int minStackTop(MinStack* obj)
//{
//
//}
//
//int minStackGetMin(MinStack* obj)
//{
//
//}
//
//void minStackFree(MinStack* obj)
//{
//
//}
//int main()
//{
//	system("pause");
//	return 0;
//}