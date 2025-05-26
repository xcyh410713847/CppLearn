#include <iostream>
#include <vector>
#include <queue>
#include <time.h>
using namespace std;

// Blossom算法类，用于求解一般图的最大匹配
class Blossom
{
    int n;                   // 顶点数
    vector<vector<int>> adj; // 邻接表表示图
    vector<int> match;       // 记录每个点的匹配点（-1表示未匹配）
    vector<int> parent;      // BFS搜索树中的父节点
    vector<int> base;        // 基点（用于处理花结构）
    vector<bool> in_blossom; // 标记某个点是否在当前花结构中
    vector<bool> visited;    // 标记BFS过程中是否访问过

public:
    // 构造函数，初始化图
    Blossom(int num_nodes) : n(num_nodes), adj(num_nodes), match(num_nodes, -1) {}

    // 添加无向边
    void addEdge(int u, int v)
    {
        if (u == v)
        {
            return;
        }

        // 确保顶点在合法范围内
        if (u < 0 || u >= n || v < 0 || v >= n)
        {
            return;
        }

        // 不要重复添加边
        for (int neighbor : adj[u])
        {
            if (neighbor == v)
            {
                return;
            }
        }

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 主过程，计算最大匹配数
    int maxMatching()
    {
        match.assign(n, -1); // 每次求解前清空匹配
        int matching_size = 0;
        for (int u = 0; u < n; ++u)
        {
            if (match[u] == -1)
            {
                int v = findAugmentingPath(u);
                // 沿增广路修改匹配关系
                while (v != -1)
                {
                    int pv = parent[v];
                    int ppv = (pv != -1) ? match[pv] : -1;
                    match[v] = pv;
                    if (pv != -1)
                        match[pv] = v;
                    v = ppv;
                }
            }
        }

        // 统计匹配对数
        for (int u = 0; u < n; ++u)
        {
            if (match[u] != -1 && u < match[u])
                matching_size++;
        }
        return matching_size;
    }

    // 获取某个点的匹配点
    int getMatch(int u) const
    {
        if (u < 0 || u >= n)
        {
            return -1; // 如果u不在合法范围内，返回-1
        }

        return match[u];
    }

private:
    // 寻找u和v的最近公共祖先（LCA），用于处理花结构
    int findLCA(int root, int u, int v)
    {
        vector<bool> in_path(n, false);
        int x = u;
        // 标记从u到根的路径
        while (true)
        {
            x = base[x];
            in_path[x] = true;
            if (x == root)
                break;
            if (match[x] == -1)
                break; // 若无匹配点，结束
            x = parent[match[x]];
            if (x == -1)
                break;
        }
        x = v;
        // 从v往上找第一个在u路径上的点
        while (true)
        {
            x = base[x];
            if (in_path[x])
                return x;
            if (match[x] == -1)
                break;
            x = parent[match[x]];
            if (x == -1)
                break;
        }
        return -1; // 理论上不会到这里
    }

    // 标记花结构中的点
    void markBlossom(int lca, int u)
    {
        while (base[u] != lca)
        {
            int v = match[u];
            if (v == -1)
                break;
            in_blossom[base[u]] = in_blossom[base[v]] = true;
            if (parent[v] == -1)
                break;
            u = parent[v];
            if (u == -1)
                break;
            if (base[u] != lca)
                parent[u] = v;
        }
    }

    // BFS查找增广路，返回增广路的末端点
    int findAugmentingPath(int start)
    {
        queue<int> q;
        visited.assign(n, false); // 重置访问状态
        parent.assign(n, -1);     // 重置父节点
        base.resize(n);           // 初始化基点
        for (int i = 0; i < n; ++i)
            base[i] = i;

        q.push(start);
        visited[start] = true;

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            for (int v : adj[u])
            {
                // 跳过同一基点或已经匹配的点
                if (base[u] == base[v] || match[u] == v)
                    continue;

                // 发现花结构，处理缩环
                if (v == start || (match[v] != -1 && parent[match[v]] != -1))
                {
                    int lca = findLCA(start, u, v);
                    if (lca == -1)
                        continue;
                    in_blossom.assign(n, false);
                    markBlossom(lca, u);
                    markBlossom(lca, v);

                    // 缩环后所有在花中的点都看作基点为LCA
                    for (int i = 0; i < n; ++i)
                    {
                        if (in_blossom[base[i]])
                        {
                            base[i] = lca;
                            if (!visited[i])
                            {
                                visited[i] = true;
                                q.push(i);
                            }
                        }
                    }
                }
                // 发现未访问过的点，拓展增广路
                else if (parent[v] == -1)
                {
                    parent[v] = u;
                    if (match[v] == -1)
                        return v; // 找到未匹配点，返回
                    if (!visited[match[v]])
                    {
                        q.push(match[v]);
                        visited[match[v]] = true;
                    }
                }
            }
        }
        return -1; // 没有增广路
    }
};

int main()
{
    while (true)
    {
        srand(static_cast<unsigned>(time(0))); // 初始化随机数种子
        int count = 10000;
        while (count > 0)
        {
            count--;
            Blossom blossom(8);

            // 随机添加一些边，生成随机图
            for (int i = 0; i < 8; ++i)
            {
                for (int j = i + 1; j < 8; ++j)
                {
                    if (rand() % 2)
                    { // 随机决定是否添加边
                        blossom.addEdge(i, j);
                    }
                }
            }

            // 输出最大匹配数
            cout << count << " Maximum matching size: " << blossom.maxMatching() << endl;
        }

        // 休眠1秒，避免输出过快
        _sleep(1000);
    }

    return 0;
}