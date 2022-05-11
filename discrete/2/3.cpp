// ! 最大流

#include <iostream>
#include <queue>
#include <vector>
#include <array>
using namespace std;

constexpr int maxn = 105;
constexpr int INF = 1 << 30;

struct edge
{
    int from, to, flow;
};
int n, m, s, t;
vector<edge> es;
array<vector<int>, maxn> G;

void addedge(int u, int v, int c)
{
    es.emplace_back(edge{u, v, c});
    es.emplace_back(edge{v, u, 0});
    G[u].push_back(es.size() - 2);
    G[v].push_back(es.size() - 1);
}

array<bool, maxn> vis;
array<int, maxn> pre;
bool bfs()
{
    vis.fill(0);
    queue<int> que;
    que.push(s);
    vis[s] = true;
    while (!que.empty())
    {
        int tmp = que.front();
        que.pop();
        for (int i : G[tmp])
        {
            const edge& e = es[i];
            if (!vis[e.to] && e.flow > 0)
            {
                vis[e.to] = 1;
                que.push(e.to);
                pre[e.to] = i;
            }
        }
    }
    return vis[t];
}

int max_flow()
{
    int answer = 0;
    while (bfs())
    {
        int min_flow = INF;
        int pos = t;
        while (pos != s)
        {
            min_flow = min(min_flow, es[pre[pos]].flow);
            pos = es[pre[pos]].from;
        }
        pos = t;
        while (pos != s)
        {
            es[pre[pos]].flow -= min_flow;
            es[pre[pos] ^ 1].flow += min_flow;
            pos = es[pre[pos]].from;
        }
        answer += min_flow;
    }
    return answer;
}


int main()
{
    cin >> n >> m >> s >> t;
    for (int i = 0; i < m; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        addedge(u, v, c);
        addedge(v, u, c);
    }
    int ans = max_flow();
    cout << ans;
    return 0;
}