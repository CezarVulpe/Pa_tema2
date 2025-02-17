#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <fstream>
#include <algorithm>

#define MOD 1000000007

using namespace std;

ifstream fin("numarare.in");
ofstream fout("numarare.out");

vector<int> topological_sort(int N, const vector<vector<int>>& adj) {
    vector<int> in_degree(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        for (int neighbor : adj[i]) {
            ++in_degree[neighbor];
        }
    }

    queue<int> q;
    for (int i = 1; i <= N; ++i) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> order;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        order.push_back(node);

        for (int neighbor : adj[node]) {
            if (--in_degree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    return order;
}

int main() {
    int N, M;
    fin >> N >> M;

    vector<vector<int>> graph1(N + 1), graph2(N + 1);
    unordered_map<int, unordered_set<int>> edges1, edges2;

    for (int i = 0; i < M; ++i) {
        int x, y;
        fin >> x >> y;
        graph1[x].push_back(y);
        edges1[x].insert(y);
    }

    for (int i = 0; i < M; ++i) {
        int x, y;
        fin >> x >> y;
        graph2[x].push_back(y);
        edges2[x].insert(y);
    }

    vector<vector<int>> common_graph(N + 1);
    for (int i = 1; i <= N; ++i) {
        for (int neighbor : graph1[i]) {
            if (edges2[i].find(neighbor) != edges2[i].end()) {
                common_graph[i].push_back(neighbor);
            }
        }
    }

    vector<int> topo = topological_sort(N, common_graph);

    vector<long long> dp(N + 1, 0);
    dp[1] = 1;

    for (int node : topo) {
        for (int neighbor : common_graph[node]) {
            dp[neighbor] = (dp[neighbor] + dp[node]) % MOD;
        }
    }

    fout << dp[N] << endl;
    return 0;
}
