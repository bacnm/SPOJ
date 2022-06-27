#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool check_func(string query, string substring)
{
    int N = query.length();
    int M = substring.length();
    int count = 0;
    if (N < M)
        return false;
    else
    {

        for (int i = 0; i <= N - M; i++)
        {
            count = 0;
            for (int j = 0; j < M; j++)
            {
                if (query[i + j] == substring[j])
                {
                    count++;
                }
                else
                    break;
            }
            if (count == M)
                break;
        }
        if (count == M)
            return true;
        else
            return false;
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    int tcs = 0;
    vector<string> list;
    cin >> tcs;

    for (int tc = 0; tc < tcs; tc++)
    {
        string query;
        int number = 0;
        bool check = false;
        cin >> number;
        cin >> query;

        if (number == 0)
            list.push_back(query);
        else
        {
            for (int i = 0; i < list.size(); i++)
            {
                if (check_func(query, list[i]))
                {
                    check = true;
                    break;
                }
            }
            if (check)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}