// ! 色数

#include <iostream>
#include <vector>
#include <array>
#include <set>
#define maxn 16
using namespace std;


int n, m;
int getcolor(array<array<int, maxn>, maxn> a, int size);
int mapn(int x,int y, int z)
{
    if (z < x)
        return z;
    else if (z < y)
        return z - 1;
    else
        return z - 2;
}
void print(array<array<int, maxn>, maxn> a)
{
    for (int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                cout << a[i][j] << " ";
            cout << endl;
        }
    cout << endl;
}
int main()
{
    cin >> n >> m;
    array<vector<int>, maxn> pre;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        for (int k = 0; k < x; k++)
        {
            int tmp;
            cin >> tmp;
            pre[i].push_back(tmp);
        }
    }

    bool empty = true;
    for (int i = 0; i < n; i++)
    {
        if (pre[i].size() != 0) empty = false;
    }
    if (empty)
    {
        cout << 1;
        return 0;
    }
    array<array<int, maxn>, maxn> t;
    for (int i = 0; i < maxn; i++)
        t[i].fill(0);
    for (int i = 0; i < n; i++)
        for (auto k : pre[i])
            for (int j = i + 1; j < n; j++)
                for (auto l : pre[j])
                    if (k == l) t[i][j] = t[j][i] = 1;
    cout << getcolor(t, n);
    return 0;
}

int getcolor(array<array<int, maxn>, maxn> a, int size)
{
    if (size == 1) return 1;

    bool full = true;
    int x, y;
    for (int i = 0; i < size; i++)
    {
        bool t = false;
        for (int j = i + 1; j < size; j++)
        {
            if (a[i][j] == 0)
            {
                full = false;
                x = i;
                y = j;
                t = true;
                break;
            }
        }
        if (t) break;
    }
    if (full) return size;
    array<array<int, maxn>, maxn> b, c;
    b = a;
    b[x][y] = b[y][x] = 1;
    for (int i = 0; i < maxn; i++)
        c[i].fill(0);
    set<int> asso;
    for (int i = 0; i < size; i++)
    {
        if (i == x || i == y)
        {
            for (int k = 0; k < size; k++)
                if (a[i][k] == 1)
                    asso.insert(k);
            continue;
        }

        for (int j = i + 1; j < size; j++)
        {
            if (j == x || j == y)   continue;
            c[mapn(x, y, i)][mapn(x, y, j)] = c[mapn(x, y, j)][mapn(x, y, i)] = a[i][j];

        }
    }
        for (auto k : asso)
        {
                c[mapn(x, y, k)][size - 2] = c[size - 2][mapn(x, y, k)] = 1;
        }
    return min(getcolor(b, size), getcolor(c, size - 1));
}