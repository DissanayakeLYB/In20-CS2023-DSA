#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
    
    //adjacency list
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    //nodes which are not reachable have the weight of -1
    const int unreachableNode = -1;
    vector<int> distances(n + 1, unreachableNode);
    
    //distance to the starting node is 0
    distances[s] = 0;

    //enqueue the starting node
    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int currentNode = q.front();
        q.pop();

        //finding the neighbors of the current node
        for (int neighbor : graph[currentNode]) {
            // If the neighbor has not been visited, calculate its distance and enqueue it
            if (distances[neighbor] == unreachableNode) {
                //weight of each edge is 6
                distances[neighbor] = distances[currentNode] + 6;  
                q.push(neighbor);
            }
        }
    }

    //output the array of distances for each node
    vector<int> result;
    for (int i = 1; i <= n; i++) {
        //distance to the start node is not considered
        if (i != s) {
            result.push_back(distances[i]);
        }
    }

    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int m = stoi(first_multiple_input[1]);

        vector<vector<int>> edges(m);

        for (int i = 0; i < m; i++) {
            edges[i].resize(2);

            string edges_row_temp_temp;
            getline(cin, edges_row_temp_temp);

            vector<string> edges_row_temp = split(rtrim(edges_row_temp_temp));

            for (int j = 0; j < 2; j++) {
                int edges_row_item = stoi(edges_row_temp[j]);

                edges[i][j] = edges_row_item;
            }
        }

        string s_temp;
        getline(cin, s_temp);

        int s = stoi(ltrim(rtrim(s_temp)));

        vector<int> result = bfs(n, m, edges, s);

        for (size_t i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
