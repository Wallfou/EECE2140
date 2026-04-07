#include "RoutingEngine.h"

#include <fstream>
#include <iostream>

RoutingEngine::RoutingEngine(int n) : numNodes(n) {
    for (int i = 0; i < n; i++) {
        auto node = std::make_unique<Node>();
        node->id = i;
        nodes.push_back(std::move(node));
    }
}

void RoutingEngine::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "could not open " << filename << std::endl;
        return;
    }
    int u, v;
    double bw;
    while (file >> u >> v >> bw) {
        if (u < 0 || u >= numNodes || v < 0 || v >= numNodes) {
            std::cerr << "skip edge (" << u << "," << v << ") out of range\n";
            continue;
        }
        nodes[u]->edges.push_back({v, bw});
    }
}

void RoutingEngine::printGraph() const {
    for (const auto& node : nodes) {
        std::cout << "Node " << node->id << ": ";
        for (std::size_t i = 0; i < node->edges.size(); i++) {
            if (i > 0) {
                std::cout << "  ";
            }
            const auto& e = node->edges[i];
            std::cout << "-(" << e.bandwidth << ")-> " << e.to;
        }
        std::cout << std::endl;
    }
}

bool RoutingEngine::dfs(int curr, int dest, double minBW,
                        std::vector<bool>& visited, std::vector<int>& path) {
    visited[curr] = true;
    path.push_back(curr);

    if (curr == dest) {
        return true;
    }

    for (const auto& edge : nodes[curr]->edges) {
        if (!visited[edge.to] && edge.bandwidth >= minBW) {
            if (dfs(edge.to, dest, minBW, visited, path)) {
                return true;
            }
        }
    }

    path.pop_back();
    return false;
}

std::vector<int> RoutingEngine::findPath(int source, int dest, double minBW) {
    std::vector<bool> visited(numNodes, false);
    std::vector<int> path;

    if (source < 0 || source >= numNodes || dest < 0 || dest >= numNodes) {
        std::cout << "No feasible path found." << std::endl;
        return path;
    }

    if (dfs(source, dest, minBW, visited, path)) {
        std::cout << "Path found (min BW >= " << minBW << "): ";
        for (std::size_t i = 0; i < path.size(); i++) {
            std::cout << path[i];
            if (i + 1 < path.size()) {
                std::cout << " -> ";
            }
        }
        std::cout << std::endl;
    } else {
        std::cout << "No feasible path found." << std::endl;
    }

    return path;
}
