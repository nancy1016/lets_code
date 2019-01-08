#include<iostream>
using namespace std;
#include<vector>
#include<stack>
class Solution
{
	//思路：借助栈来实现
	//(1)如果栈为空或栈顶元素不等于popV[out],则进栈，in索引++
	//(2)如果栈顶元素等于popV[out],则出栈，out索引--
	//直到popV中所有元素遍历完毕，这时候检查栈：如果栈为空，则说明是正确顺序
	//如果栈不为空，则说明是错误顺序
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV)
	{
		if (pushV.size() != popV.size())
		{
			return false;
		}
		int in = 0;//遍历pushV数组的下标
		int out = 0;//遍历popV数组的下标
		while (out<popV.size())
		{
			if (_data.empty() || _data.top() != popV[out])//注意：这里不能写成pushV[in]！=popV[out],因为这样的话4就无法入栈，变成死循环
			{
				_data.push(pushV[in]);
				++in;
			}
			if (_data.top() == popV[out])
			{
				_data.pop();
				++out;
			}
		}
		if (_data.empty())
			return true;
		return false;

	}
private:
	stack<int>_data;
};



int main()
{
	Solution s;
	int a[] = { 1, 2, 3, 4, 5 };
	int b[] = { 4, 5, 3, 2, 1 };
	vector<int> pushV(a, a + sizeof(a) / sizeof(a[0]));
	vector<int> popV(b, b + sizeof(b) / sizeof(b[0]));
	int ret=s.IsPopOrder(pushV, popV);
	cout << ret << endl;
	return 0;
}