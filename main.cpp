#include <bits/stdc++.h>
using namespace std;

// Build De Bruijn Graph
unordered_map<string, vector<string>> graph;
unordered_map<string, int> indeg, outdeg;

void addEdge(string u, string v) {
    graph[u].push_back(v);
    outdeg[u]++;
    indeg[v]++;
}

// Hierholzer's Algorithm for Eulerian Path
void dfs(string u, vector<string> &path) {
    while (!graph[u].empty()) {
        string v = graph[u].back();
        graph[u].pop_back();
        dfs(v, path);
    }
    path.push_back(u);
}

int main() {
    int k;
    cin >> k;

    vector<string> reads;
    string s;
    while (cin >> s) {
        reads.push_back(s);
    }

    // Build graph
    for (string &read : reads) {
        for (int i = 0; i + k <= read.size(); i++) {
            string kmer = read.substr(i, k);
            string left = kmer.substr(0, k - 1);
            string right = kmer.substr(1, k - 1);
            addEdge(left, right);
        }
    }

    // Find start node for Eulerian path
    string start;
    for (auto &p : outdeg) {
        if (outdeg[p.first] > indeg[p.first]) {
            start = p.first;
            break;
        }
    }
    if (start.empty())
        start = graph.begin()->first;

    // Eulerian path
    vector<string> path;
    dfs(start, path);
    reverse(path.begin(), path.end());

    // Reconstruct genome
    string genome = path[0];
    for (int i = 1; i < path.size(); i++) {
        genome += path[i].back();
    }

    cout << "Assembled Genome:\n";
    cout << genome << endl;

    return 0;
}
