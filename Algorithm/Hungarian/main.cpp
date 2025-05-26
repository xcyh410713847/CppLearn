#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

class Hungarian
{
    int n;                   // 顶点数
    vector<vector<int>> adj; // 邻接表表示图
    vector<int> match;       // 匹配对
    vector<bool> visited;    // DFS访问标记

public:
    Hungarian(int num_nodes) : n(num_nodes), adj(num_nodes), match(num_nodes, -1) {}

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u); // 无向图，双向边
    }

    bool dfs(int u)
    {
        for (int v : adj[u])
        {
            if (!visited[v])
            {
                visited[v] = true;
                if (match[v] == -1 || dfs(match[v]))
                {
                    match[u] = v;
                    match[v] = u;
                    return true;
                }
            }
        }
        return false;
    }

    int maxMatching()
    {
        int matching_size = 0;
        match.assign(n, -1); // 初始化匹配对
        for (int u = 0; u < n; ++u)
        {
            if (match[u] == -1)
            {                             // 如果当前顶点未匹配
                visited.assign(n, false); // 重置访问标记
                if (dfs(u))
                {
                    matching_size++;
                }
            }
        }
        return matching_size;
    }

    int getMatch(int u) const
    {
        return match[u];
    }
};

int main()
{
    srand(static_cast<unsigned>(time(0))); // 初始化随机数种子
    Hungarian hungarian(8);

    // 随机添加一些边
    for (int i = 0; i < 8; ++i)
    {
        for (int j = i + 1; j < 8; ++j)
        {
            if (rand() % 2)
            { // 随机决定是否添加边
                hungarian.addEdge(i, j);
                cout << "Added edge: " << i << " - " << j << endl;
            }
        }
    }

    cout << "Maximum matching size: " << hungarian.maxMatching() << endl;

    // 输出匹配结果
    for (int i = 0; i < 8; ++i)
    {
        int match = hungarian.getMatch(i);
        if (match != -1 && i < match)
        { // 避免重复输出匹配对
            cout << "Matched pair: " << i << " - " << match << endl;
        }
    }

    return 0;
}
