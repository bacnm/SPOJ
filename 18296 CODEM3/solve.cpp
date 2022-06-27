#include<iostream>
using namespace std;

int inp_arr[100000];
int main()
{
    freopen("input.txt","r",stdin);
	int tcs = 0;

	cin >> tcs;
	for (int  tc = 0; tc < tcs; tc++)
	{
		int arr_size = 0;
		int count = 0, zero_point = 0;
		bool check = false;
		cin >> arr_size;


		for (int i = 0; i < arr_size; i++)
		{
			cin >> inp_arr[i];
		}

		for (int i = 0; i < arr_size; i++)
		{
			if (inp_arr[i] == 0)
			{
				if (check == false)
				{
					zero_point = i;
					check = true;
				}
			}
			else
			{
				if (check)
				{
					swap(inp_arr[zero_point], inp_arr[i]);
					i = zero_point;
					check = false;
					count++;
				}
			}
		}
		cout << count << endl;
	}
	

	return 0;
}