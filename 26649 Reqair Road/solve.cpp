#include <iostream>
#include <vector>
#include <cstdlib>
#include <set>

using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        int i;
        for (i = 0; i < n; i++)
        {
            cin >> nums[i];
        }
        int front = 0, back = 0; // Indexes for Sliding Window
        int max_len = 0;         // Maximum length of window
        int zeros = 0;           // Number of zero's in Window

        while (back < n)
        {
            if (nums[back] == 0)
                zeros++;
            if (zeros <= k)
            {
                max_len = max(back - front + 1, max_len); // update max_len
            }
            else
            {
                // Until the number of zeros less than K, adjust front
                while (zeros > k && front < back)
                {
                    if (nums[front] == 0)
                        zeros--;
                    front++;
                }
            }
            back++;
        }
        cout << max_len << endl;
    }
    return 0;
}