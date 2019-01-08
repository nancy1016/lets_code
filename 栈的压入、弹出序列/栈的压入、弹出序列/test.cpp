#include<iostream>
using namespace std;
#include<vector>
#include<stack>
class Solution
{
	//˼·������ջ��ʵ��
	//(1)���ջΪ�ջ�ջ��Ԫ�ز�����popV[out],���ջ��in����++
	//(2)���ջ��Ԫ�ص���popV[out],���ջ��out����--
	//ֱ��popV������Ԫ�ر�����ϣ���ʱ����ջ�����ջΪ�գ���˵������ȷ˳��
	//���ջ��Ϊ�գ���˵���Ǵ���˳��
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV)
	{
		if (pushV.size() != popV.size())
		{
			return false;
		}
		int in = 0;//����pushV������±�
		int out = 0;//����popV������±�
		while (out<popV.size())
		{
			if (_data.empty() || _data.top() != popV[out])//ע�⣺���ﲻ��д��pushV[in]��=popV[out],��Ϊ�����Ļ�4���޷���ջ�������ѭ��
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