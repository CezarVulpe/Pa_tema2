#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <limits>
#include <functional>

using namespace std;

typedef long long ll;
typedef pair<ll, int> pii;

const ll INF = numeric_limits<ll>::max();

void dijkstra(int start, vector<vector<pii>>& graph, vector<ll>& dist) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty()) {
        pii current = pq.top();
        pq.pop();
        ll d = current.first;
        int node = current.second;

        if (d > dist[node]) continue;

        for (auto& edge : graph[node]) {
            int neighbor = edge.second;
            ll weight = edge.first;
            if (dist[node] + weight < dist[neighbor]) {
                dist[neighbor] = dist[node] + weight;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }
}

int main() {
    ifstream fin("drumuri.in");
    ofstream fout("drumuri.out");

    int N, M;
    fin >> N >> M;

    vector<vector<pii>> graph(N + 1);
    int a, b;
    ll c;

    for (int i = 0; i < M; ++i) {
        fin >> a >> b >> c;
        graph[b].push_back({c, a});
    }

    int x, y, z;
    fin >> x >> y >> z;

    // Distance vectors
    vector<ll> dist(N + 1, INF);

    dijkstra(z, graph, dist);

    ll total_cost = dist[x] + dist[y];

    fout << total_cost << endl;

    fin.close();
    fout.close();
    return 0;
}
