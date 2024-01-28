
#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;
#define INF 0x3f3f3f3f

typedef pair<int, int> iPair;

class Graph {
    int V;
    list<iPair>* adj;

public:
    Graph(int V) {
        this->V = V;
        adj = new list<iPair>[V];
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    void shortestPath(int s) {
        priority_queue<iPair, vector<iPair>, greater<iPair> > pq;
        vector<int> dist(V, INF);

        pq.push(make_pair(0, s));
        dist[s] = 0;

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (auto i = adj[u].begin(); i != adj[u].end(); ++i) {
                int v = (*i).first;
                int weight = (*i).second;

                if (dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }

        printf("Vertex Distance from Source\n");
        for (int i = 0; i < V; ++i)
            printf("%d \t\t %d\n", i, dist[i]);
    }
};

int main() {
    int V = 5;
    Graph g(V);

    // Add your edges here
    g.addEdge(0, 1, 3);
    g.addEdge(0, 2, 6);
    g.addEdge(0, 3, 7);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 4, 4);
    g.addEdge(2, 3, 1);
    g.addEdge(2, 4, 2);
    g.addEdge(3, 4, 2);

    auto start = high_resolution_clock::now();

    g.shortestPath(0);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "Time taken by function: " << duration.count() << " nanoseconds" << endl;

    return 0;
}
