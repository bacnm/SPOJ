#include <iostream>
#include <stack>

using namespace std;

int main(int argc, char const *argv[])
{
    freopen("input.txt","r",stdin);
	int N = 0;

	stack<int> stack_arr;
	int inp_arr[1000];
	int count = 1;

	cin >> N;

	while (N != 0)
	{
		for (int i = 0; i < N; ++i)
		{
			cin >> inp_arr[i];
		}

		int index = 0;
		while (index < N)
		{
			if (inp_arr[index] == count)
			{
				count++;
				index++;
			}
			else if (stack_arr.size() > 0 && stack_arr.top() == count)
			{
				stack_arr.pop();
				count++;
			}
			else
			{
				stack_arr.push(inp_arr[index]);
				index++;
			}
		}

		while (stack_arr.size() > 0 && stack_arr.top() == count)
		{
			stack_arr.pop();
			count++;
		}

		if (count == N + 1)
			cout << "yes" << endl;
		else
			cout << "no" << endl;

		cin >> N;
	}
	return 0;
}