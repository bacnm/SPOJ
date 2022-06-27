#include <iostream>
#include<vector>
using namespace std;


int main()
{
    freopen("input.txt","r",stdin);
    int tcs = 0;

    cin >> tcs;

    for (int i = 0; i < tcs; i++)
    {
        int N = 0;
        int height[1000] = {};
        int taller[1000] = {};
        vector<int> out;

        cin >> N;
        for (int i = 0; i < N; i++)
        {
            cin >> height[i];
        }
        for (int i = 0; i < N; i++)
        {
            cin >> taller[i];
        }

        for (int i = 0; i < N-1; i++)
        {
            for (int j = i+1; j < N; j++)
            {
                if(height[i] > height[j])
                    swap(height[i],height[j]);
                    swap(taller[i],taller[j]);
            }
        }
        int *arr = new int[N];
        for (int i = 0; i < N; i++)
        {
            arr[i] = -1;
        }
        
        for (int i = 0; i < N; i++)
        {
            if(arr[taller[i]] == -1 )
                arr[taller[i]] = height[i];
            else
            {

            }
        }

        
        

    }

    return 0;
}