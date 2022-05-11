// ! 欧拉回路

#include <iostream>
#include <array>
#include <stack>
using namespace std;
#define maxn 1050
stack<int> dfsorder;
int a[maxn];
int b[maxn];
int real[maxn];
int times[maxn];
int n;
int num = 0;
int repeat[maxn];
array<array<int, maxn>, maxn> c;
int getnumber(int x)
{
    for (int i = 0; i < num; i++)
    {
        if (real[i] == x)
        return i;
    }
}
int getanswernum(int x, int y)
{
    for (int i = 0; i < n; i++)
    {
        if (((x == a[i] && y == b[i]) || (x == b[i] && y == a[i])) && repeat[i] == 0)
        {
            repeat[i] = 1;
            return i;
        }
    }
}
void dfs();
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
        times[a[i]]++;
        times[b[i]]++;
        bool finda = true, findb = true;
        for (int j = 0; j < i; j++)
        {
            if (a[j] == a[i] || b[j] == a[i])
            {
                finda = false;
                break;
            }
        }
        for (int j = 0; j < i; j++)
        {
            if (a[j] == b[i] || b[j] == b[i])
            {
                findb = false;
                break;
            }
        }
        if (finda)
        {
            real[num++] = a[i];
        }
        if (findb)
        {
            real[num++] = b[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        c[getnumber(a[i])][getnumber(b[i])] += 1;
        c[getnumber(b[i])][getnumber(a[i])] += 1;
    }
    int start;
    for (int i = 0; i < maxn; i++)
    {
        if (times[i] % 2 == 1)
            {
                start = i;
                break;
            }
        else if (i == maxn - 1)
            {
                start = a[0];
                break;
            }
        
    }
    dfs(getnumber(start));
    return 0;
}
void dfs(int num_)
{
    dfsorder.push(num_);
    for (int i = 0; i < num; i++)
    {
        if (c[num_][i] != 0)
        {
            c[num_][i]--;
            c[i][num_]--;
            dfs(i);
        }
        else if (i == num - 1)
        {
            dfsorder.pop();
            int tmp = dfsorder.top();
            cout << getanswernum(real[num_], real[tmp]) + 1 << ' ';
            dfsorder.pop();
            if (dfsorder.empty())
            {
                exit(0);
            }
            dfs(tmp);
        }
    }
}