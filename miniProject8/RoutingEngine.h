#ifndef ROUTING_ENGINE_H
#define ROUTING_ENGINE_H

#include <memory>
#include <string>
#include <vector>

struct Edge {
    int to;
    double bandwidth;
};

struct Node {
    int id;
    std::vector<Edge> edges;
};

class RoutingEngine {
private:
    std::vector<std::unique_ptr<Node>> nodes;
    int numNodes;

    bool dfs(int curr, int dest, double minBW, std::vector<bool>& visited,
             std::vector<int>& path);

public:
    explicit RoutingEngine(int n);
    void loadFromFile(const std::string& filename);
    void printGraph() const;
    std::vector<int> findPath(int source, int dest, double minBW);
};

#endif
