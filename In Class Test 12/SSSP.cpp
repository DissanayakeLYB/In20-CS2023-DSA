#include <iostream>
#include <climits>

#define V 6 //number of vertices

using namespace std;

int minTime(int timeTaken[], bool visited[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (!visited[v] && timeTaken[v] <= min) {
            min = timeTaken[v];
            min_index = v;
        }
    }

    return min_index;
}

void dijkstra(int graph[V][V], int source) {
    int timeTaken[V];
    bool visited[V];

    for (int i = 0; i < V; i++) {
        timeTaken[i] = INT_MAX;
        visited[i] = false;
    }

    //time taken from the source city to itself is zero
    timeTaken[source] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minTime(timeTaken, visited);

        visited[u] = true;

        //update the time taken to the adjacent cities of the selected city
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && timeTaken[u] != INT_MAX &&
                timeTaken[u] + graph[u][v] < timeTaken[v]) {
                timeTaken[v] = timeTaken[u] + graph[u][v];
            }
        }
    }

    //print the shortest time taken from the source to each city
    cout << "Starting Node : " << source << "\n";
    for (int i = 0; i < V; i++) {

        if (i == source){
            continue;
        }
        else{
            cout << "Time taken to city " << i << " : " << timeTaken[i] << "\n";
        }

    }

    //calculate and print the average time taken from the source to all other cities
    int totalTime = 0;
    int numCities = V - 1; //exclude the source city itself
    for (int i = 0; i < V; i++) {
        if (i != source) {
            totalTime += timeTaken[i];
        }
    }

    double averageTime = static_cast<double>(totalTime)/numCities;
    cout << "Average time from city " << source << " : " << averageTime << "\n";

}

int main() {
    //weighted adjacent matrix
    int graph[V][V] = {
        {0, 10, 0, 0, 15, 5},
        {10, 0, 10, 30, 0, 0},
        {0, 10, 0, 12, 5, 0},
        {0, 30, 12, 0, 0, 20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0}
    };

    int source = 0;

    dijkstra(graph, source);

    return 0;
}
