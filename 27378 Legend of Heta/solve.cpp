#include<iostream>
#include<string>
#include<vector>
using namespace std;



int main()
{
    freopen("input.txt","r",stdin);
    string inp_str;
    vector<string> list;
    string temp;
    int list_count = 0;
    cin >> inp_str;
    cin >> list_count;
    for ( int i = 0; i < list_count;i++)
    {
        cin >> temp;
        list.push_back(temp);
    }



    return 0;
}