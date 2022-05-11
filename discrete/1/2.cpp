// ! Dijkstra

#include <iostream>
#include <array>
#include <vector>
#include <cmath>
#include <string.h>
#include <algorithm>
#include <iomanip>
using namespace std;
#define maxn 105
#define INF 0x3f3f3f
struct node
{
    double x;
    double y;
    double cost;
    int num;
};
struct way
{
    int left;
    int right;
};
int n, m;
array<vector<node>,maxn> pos;
vector<way> rode;
double getmin(double a, double b)
{
    if (a < b)  return a;
    else return b;
}
double Dijkstra(int start, int end);
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        node tmp;
        cin >> tmp.x >> tmp.y;
        pos[i].push_back(tmp);
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        way tmp;
        cin >> tmp.left >> tmp.right;
        tmp.left--;
        tmp.right--;
        double cost = sqrt(pow((pos[tmp.left][0].x - pos[tmp.right][0].x),2) + pow((pos[tmp.left][0].y - pos[tmp.right][0].y), 2));
        pos[tmp.left].push_back(pos[tmp.right][0]);
        pos[tmp.right].push_back(pos[tmp.left][0]);
        (*pos[tmp.left].rbegin()).cost = cost;
        (*pos[tmp.right].rbegin()).cost = cost;
        (*pos[tmp.left].rbegin()).num = tmp.right;
        (*pos[tmp.right].rbegin()).num = tmp.left;
        rode.push_back(tmp);
    }
    int first[5] = {0};
    double costt[5] = {0};
    for (int i = 0; i < 3; i++)
    {
        cin >> first[i] >> costt[i];
        first[i]--;
    }
    double costtt[5] = {0};
    for (int i = 0; i < 3; i++)
    {
        for (auto it = pos[rode[first[i]].left].begin(); it != pos[rode[first[i]].left].end(); it++)
        {
            if ((*it).num == rode[first[i]].right)
            {
                costtt[i] = (*it).cost - costt[i]; 
                break;
            }
        }
    }
    double result[3] = {0};
    for (int i = 0; i < 2; i++)
    {
        double min1 =getmin(Dijkstra(rode[first[i]].left, rode[first[i+1]].left) + costt[i] + costt[i+1], Dijkstra(rode[first[i]].left, rode[first[i+1]].right) + costt[i] + costtt[i+1]);
        double min2 =getmin(Dijkstra(rode[first[i]].right, rode[first[i+1]].left) + costtt[i] + costt[i+1], Dijkstra(rode[first[i]].right, rode[first[i+1]].right) + costtt[i] + costtt[i+1]);
        result[i] = getmin(min1, min2);
    }
    cout << fixed << setprecision(2) << result[0] + result[1] << endl;
}

double Dijkstra(int start, int end)
{
    if (start == end)
        return 0;
    vector<int> in;
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        in.push_back(i);
    }
    in.erase(in.begin() + start);
    res.push_back(start);
    double dis[105] = {0};
    for (int i = 0; i < n; i++)
    {
        dis[i] = INF;
    }
    dis[start] = 0;
    for (int i = 1; i < pos[start].size(); i++)
    {
        dis[pos[start][i].num] = pos[start][i].cost;
    }
    for (int k = 0; k < 105;  k++)
    {
    double min = INF;
    int poss;
    for(auto it : in)
    {
        if (dis[it] < min)
        {
            poss = it;
            min = dis[it];
        }
    }
    if (poss == end)
        return min;
    res.push_back(poss);
    for (auto it = in.begin(); it != in.end(); it++)
    {
        if ((*it) == poss)
            {
                in.erase(it);
                break;
            }

    }
    for (int i = 1; i < pos[poss].size(); i++)
    {
        dis[pos[poss][i].num] = getmin(dis[pos[poss][i].num], dis[poss] + pos[poss][i].cost);
    }
    }

}