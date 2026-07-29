class Solution {
public:
    vector<int> bfs(vector<vector<int>>& adjList, int source, int vertex) {
        vector<bool> visited(vertex, false);
        vector<int> ans;
        queue<int> q;

        visited[source] = true;
        q.push(source);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for (auto neighbour : adjList[node]) {
                if (!visited[neighbour]) {
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }

        return ans;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        int vertex = n;
        vector<vector<int>> adjList(vertex);

        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        vector<int> ans = bfs(adjList, source, n);
        for (auto it : ans) {
            if (it == destination) {
                return true;
            }
        }

        return false;
    }
};