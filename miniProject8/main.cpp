#include "RoutingEngine.h"

#include <iostream>

int main() {
    RoutingEngine engine(6);
    engine.loadFromFile("network.txt");

    std::cout << "Network Topology: " << std::endl;
    engine.printGraph();

    std::cout << std::endl;
    std::cout << "Finding paths: " << std::endl;
    engine.findPath(0, 5, 50);
    engine.findPath(0, 5, 100); // i dont think a path for this exists
    engine.findPath(0, 5, 200);

    return 0;
}
