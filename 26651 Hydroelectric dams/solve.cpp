#include<iostream>
using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    int tcs;
    cin >> tcs;
    for (int i = 0; i < tcs; i++)
    {
        int N;
        cin >> N;
        int wall[10001];
        int max1 = 3, max2 = 3; /* index = wall; wall >= 3, value = height of wall*/

        for (int i = 3; i <= 3+N; i++)
        {
            cin >> wall[i];
        }

        for( int i = 4; i <= 3+N; i++)
        {
            if( wall[i] >= wall[max1])
            {
                max1 = i;
            }
        }

        for( int i = 4; i <= 3+N; i++)
        {
            if( wall[i] >= wall[max2] && i != max1)
            {
                max2 = i;
            }
        }

        int x , y = wall[max2];
        int size;

        if( max1 < max2)
        {
            x = max2 - max1 + 1;
            size = x*y - 2*wall[max2];
            for (int i = max1 + 1; i < max2 ; i++)
            {
                size -= wall[i];
            }
            
        }
        else
        {
            x = max1 - max2 + 1;
            size = x*y - 2*wall[max2];
            for (int i = max2 + 1; i < max1 ; i++)
            {
                size -= wall[i];
            }
        }
        
        cout << size<<endl;

    }
    
    return 0;
}