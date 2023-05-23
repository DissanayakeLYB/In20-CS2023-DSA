#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge {
    int weight;
    int start;
    int finish;

    Edge(int w, int s, int f) : weight(w), start(s), finish(f) {}
};

// Define comparison operator for Edge
bool operator>(const Edge& e1, const Edge& e2) {
    return e1.weight > e2.weight;
}

struct Graph {
    int numNodes;
    vector<vector<Edge>> adjList;

    Graph(int n) : numNodes(n), adjList(n) {}

    void addEdge(int u, int v, int weight) {
        adjList[u].emplace_back(weight, u, v);
        adjList[v].emplace_back(weight, v, u);
    }
};

vector<Edge> primMST(const Graph& graph, int startNode) {
    int numNodes = graph.numNodes;
    vector<bool> visited(numNodes, false);
    vector<Edge> mst;
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

    pq.push(Edge(0, startNode, startNode));

    while (!pq.empty()) {
        int u = pq.top().finish;
        int weight = pq.top().weight;
        int start = pq.top().start;
        pq.pop();

        if (visited[u])
            continue;

        visited[u] = true;
        if (u != startNode)
            mst.emplace_back(weight, start, u);

        for (const auto& neighbor : graph.adjList[u]) {
            int v = neighbor.finish;
            int w = neighbor.weight;

            if (!visited[v])
                pq.push(Edge(w, u, v));
        }
    }

    return mst;
}

void printMST(const vector<Edge>& mst) {
    cout << "starting edge - ending edge : weight" << endl;
    for (const auto& edge : mst) {
        cout << "     " << edge.start << "        -     " << edge.finish << "       :   " << edge.weight << endl;
    }
}

int main() {
    int numNodes = 6;
    Graph graph(numNodes);

    //(node u, node v, weight of the edge)
    graph.addEdge(0, 1, 3);
    graph.addEdge(0, 5, 1);
    graph.addEdge(1, 2, 2);
    graph.addEdge(1, 3, 1);
    graph.addEdge(1, 4, 10);
    graph.addEdge(2, 3, 3);
    graph.addEdge(2, 5, 5);
    graph.addEdge(3, 4, 5);
    graph.addEdge(4, 5, 4);

    vector<Edge> mst = primMST(graph, 0);

    printMST(mst);

    return 0;
}
