// ! 并查集

#include <iostream>
#include <queue>
#include <array>
#include <vector>
#define maxn 102
#define Max 0xf8f8f8
using namespace std;

int n, m, s, t;
array<array<int, maxn>, maxn> p;
int f[maxn], rank_[maxn];
int ans = Max;
void init();
int find(int pos);
void merge(int i, int j);
array<array<int, maxn>, maxn> answer;
void bfs(int pos, int deep);
array<bool, maxn> visited;
array<int, maxn> way;
int deepest;
void dfs(int pos);
array<int, maxn> d;

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
    cin >> n >> m >> s >> t;
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        p[x - 1][y - 1] = p[y - 1][x - 1] = z;
    }

    int size = 0;
    init();
    while (size < n - 1)
    {
        int maxval = -1;
        int posx, posy;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (p[i][j] > maxval)
                {
                    maxval = p[i][j];
                    posx = i;
                    posy = j;
                }
            }
        }
        if (find(posx) != find(posy))
        {
            answer[posx][posy] = answer[posy][posx] = maxval;
            merge(posx, posy);
            p[posx][posy] = p[posy][posx] = 0;
            size++;
        }
        else
        {
            p[posx][posy] = p[posy][posx] = 0;
        }
    }

    //print(answer);


    visited[s - 1] = true;
    /*bfs(s - 1, 0);
    way[0] = s - 1;
    for (int i = 0; i < deepest; i++)
    {
        ans = min(ans, answer[way[i]][way[i + 1]]);
    }
    cout << ans;*/
    d[s - 1] = Max;
    dfs(s - 1);
    cout << d[t - 1];
    return 0;
}
void init()
{
    for (int i = 0; i < maxn; i++)
    {
        f[i] = i;
        rank_[i] = 1;
    }
}
int find(int pos)
{
    return pos == f[pos] ? pos : (f[pos] = find(f[pos]));
}

void merge(int i, int j)
{
    int x = find(i), y = find(j);
    if (rank_[x] <= rank_[y])
        f[x] = y;
    else
        f[y] = x;
    if (rank_[x] == rank_[y] && x != y)
        rank_[y]++;
}

void bfs(int pos, int deep)
{
    if (pos == t - 1)   
    {
        deepest = deep;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (answer[pos][i] != 0 && visited[i] == false)
        {
            way[deep + 1] = i;
            visited[i] = true;
            bfs(i, deep + 1);
            //visited[i] = false;
        }
    }
}//wrong


void dfs(int pos) {
    for (int i = 0; i < n; i++) {
        if (answer[pos][i] != 0 && !visited[i]) {
            d[i] = min(d[pos], answer[pos][i]);
            visited[i] = 1;
            dfs(i);
        }
    }
}