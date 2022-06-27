#include <iostream>
using namespace std;

int main() 
{
	freopen("input.txt","r",stdin);
	int tcs;
    cin >> tcs;
	bool check[10001];
	while(tcs--)
	{
		int N;
		cin>> N;
		for( int i = 1 ; i <= N; i++)
		{
			check[i] = true;
		}
		for( int i = 2 ; i <= N; i++)
		{
			if( check[i])
			{
				for (int j = 2 * i; j <= N; j += i)
				{
        			check[j] = false;
      			}
			}
		}
		for( int i = N; i >= 1;  i--)
		{
			if ( check[i] )
			{
				cout<<i<<endl;
				break;
			}
		}
	}
	

	return 0;
}