long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
    if (c_lib <= c_road) {
        // Cheaper to build libraries in each city
        return static_cast<long>(n) * c_lib;
    }
    
    // Create an adjacency list to represent the cities and their connections
    vector<vector<int>> adjacencyList(n + 1);
    for (const auto& city : cities) {
        int city1 = city[0];
        int city2 = city[1];
        adjacencyList[city1].push_back(city2);
        adjacencyList[city2].push_back(city1);
    }
    
    // Perform DFS on the cities to count the number of connected components
    vector<bool> visited(n + 1, false);
    long totalCost = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            // Each connected component requires at least one library
            totalCost += c_lib;
            
            // Perform DFS to visit all cities in the connected component
            stack<int> stk;
            stk.push(i);
            visited[i] = true;
            
            while (!stk.empty()) {
                int currCity = stk.top();
                stk.pop();
                
                // Visit each unvisited neighbor and mark it as visited
                for (int neighbor : adjacencyList[currCity]) {
                    if (!visited[neighbor]) {
                        stk.push(neighbor);
                        visited[neighbor] = true;
                        
                        // Each unvisited city in the connected component requires a road
                        totalCost += c_road;
                    }
                }
            }
        }
    }
    
    return totalCost;
}
