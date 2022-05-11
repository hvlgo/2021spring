#include "myfriend.h"
#include "newslist.h"
#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n;
    newslist news;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        string str;
        cin >> tmp >> str;
        myfriend* f = new myfriend(tmp, str);
        news.addfriend(*f);
    }
    cin >> m;
    for (int j = 0; j < m; j++)
    {
        int tmp;
        string str;
        cin >> tmp >> str;
        bool find = false;
        for (auto i : news.getlist())
        {
            if (i.getid() == tmp)
            {
                i.addmessage(str);
                news.top(i);
                find = true;
                break;
            }
        }
        if (!find)
        {
            myfriend* f = new myfriend(tmp, str);
            news.addfriend(*f);
        }
    }
    for (auto i : news.getlist())
    {
        cout << i;
    }
}