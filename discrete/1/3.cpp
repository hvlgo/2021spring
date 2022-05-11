//  ! PT graph

#include <iostream>
#include <vector>
#include <array>
#include <queue>
using namespace std;

#define maxn 105
struct node
{
    int number;
    int cost;
};
array<vector<node>, maxn> course;
array<vector<int>, maxn> pre;
int n;
int indegree[maxn];
int isend[maxn];
int time_[maxn];
int time_end[maxn];
vector<node> top;

void topsort()
{
    top.push_back(course[n + 1][0]);
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (indegree[j] == 0)
            {  
                indegree[j] = -1;
                top.push_back(course[j][0]);
                for (size_t k = 1; k < course[j].size(); k++)
                {
                    indegree[course[j][k].number]--;
                }
            }
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        node tmp;
        cin >> tmp.cost;
        tmp.number = i;
        course[i].push_back(tmp);
        int c;
        cin >> c;
        for (int j = 0; j < c; j++)
        {
            int tmp;
            cin >> tmp;
            pre[i].push_back(tmp);
            isend[i]++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (auto it : pre[i])
        {
            course[it - 1].push_back(course[i][0]);
            indegree[i]++;
        }
    }
    node first, end;
    first.cost = 0;
    first.number = n + 1;
    end.number = n;
    end.cost = 0;
    course[n + 1].push_back(first);
    course[n].push_back(end);
    indegree[n + 1] = 0;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            course[n + 1].push_back(course[i][0]);
        }
        if (isend[i] != 0 && indegree[i] != 0)
        {
            indegree[n]++;
            course[i].push_back(course[n][0]);
        }
    }
    topsort();
    time_[top[0].number] = 0;
    for (int i = 1; i <= n + 1; i++)
    {
        int maxval = -1;
        for (int l = 0; l <= n + 1; l++)
        {
            for (size_t s = 1; s < course[l].size(); s++)
            {
                if (course[l][s].number == top[i].number && course[l][0].cost + time_[course[l][0].number] > maxval)
                {
                    maxval = course[l][0].cost + time_[course[l][0].number];
                }
            }
        }
        time_[top[i].number] = maxval;
    }
    time_end[top[n + 1].number] = time_[top[n + 1].number];
    for (int i = n; i >= 0; i--)
    {
        int minval = 0x3f3f3f;
        for (size_t j = 1; j < course[top[i].number].size(); j++)
        {
            if (time_end[course[top[i].number][j].number] - course[top[i].number][0].cost < minval)
            {
                minval = time_end[course[top[i].number][j].number] - course[top[i].number][0].cost;
            }
        }
        time_end[top[i].number] = minval;
    }
    for (int i = 0;  i < n; i++)
    {
        cout << time_[i] + course[i][0].cost << ' ';
        if (time_end[i] - time_[i] == 0)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}