#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <stack>

using namespace std;

void dfs(int node, vector<vector<int>>& adj,
vector<bool>& visited, stack<int>& st) {
    visited[node] = true;
    for (auto& neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited, st);
        }
    }
    st.push(node);
}

int longestPath(int start, int end, vector<vector<int>>& adj, int n) {
    vector<bool> visited(n, false);
    stack<int> st;
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i, adj, visited, st);
        }
    }

    vector<int> dist(n, 0);
    dist[start] = 1;
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        if (dist[u] != 0) {
            for (int v : adj[u]) {
                if (dist[u] + 1 > dist[v]) {
                    dist[v] = dist[u] + 1;
                }
            }
        }
    }
    return dist[end];
}

int main() {
    ifstream fin("trenuri.in");
    ofstream fout("trenuri.out");

    string start_city, end_city;
    fin >> start_city >> end_city;

    int M;
    fin >> M;

    unordered_map<string, int> city_index;
    vector<vector<int>> adj;
    int index = 0;

    for (int i = 0; i < M; ++i) {
        string x, y;
        fin >> x >> y;
        if (city_index.find(x) == city_index.end()) {
            city_index[x] = index++;
            adj.push_back({});
        }
        if (city_index.find(y) == city_index.end()) {
            city_index[y] = index++;
            adj.push_back({});
        }
        adj[city_index[x]].push_back(city_index[y]);
    }

    int start = city_index[start_city];
    int end = city_index[end_city];

    fout << longestPath(start, end, adj, index) << endl;

    fin.close();
    fout.close();

    return 0;
}
