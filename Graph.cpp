// Ariel shamay
// 207565573
// arielsh49@gmail.com
#include "Graph.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>

using namespace ariel;
using namespace std;

// Function to load a graph from an adjacency matrix
void Graph::loadGraph(const std::vector<std::vector<int>>& matrix) {
    // Check if the matrix is empty
    if (matrix.empty()) {
        throw std::invalid_argument("The graph cannot be empty");
    }

    // Check if the matrix is square
    size_t size = matrix.size();
    for (const auto& row : matrix) {
        if (row.size() != size) {
            throw std::invalid_argument("Invalid graph: The graph is not a square matrix.");
        }
    }

    // Set the graph's directed flag and load the matrix
    directed = this->isDirected();
    this->adjacencyMatrix = matrix;
}

// Function to print the graph
void Graph::printGraph() const {
    size_t vertexCount = getNumberOfNodes();
    int edgeCount = 0;

    for (const auto& row : adjacencyMatrix) {
        for (const auto& element : row) {
            if (element != 0) {
                edgeCount++;
            }
        }
    }

    // Adjust edge count for undirected graphs
    if (!getDirected()) {
        edgeCount /= 2;
    }

    // Print graph details
    std::cout << "Graph with " << vertexCount << " vertices and " << edgeCount << " edges.\n";

    for (const auto& row : adjacencyMatrix) {
        for (const auto& element : row) {
            std::cout << element << ' ';
        }
        std::cout << '\n';
    }
}

// Function to check if the graph is directed
bool Graph::isDirected() const {
    for (size_t i = 0; i < adjacencyMatrix.size(); ++i) {
        for (size_t j = 0; j < adjacencyMatrix[i].size(); ++j) {
            if (adjacencyMatrix[i][j] != adjacencyMatrix[j][i]) {
                return true;
            }
        }
    }
    return false;
}

// Function to get all edges of the graph
std::vector<std::pair<size_t, std::pair<size_t, int>>> Graph::getEdges() const {
    std::vector<std::pair<size_t, std::pair<size_t, int>>> edges;
    for (size_t i = 0; i < adjacencyMatrix.size(); ++i) {
        for (size_t j = 0; j < adjacencyMatrix[i].size(); ++j) {
            if (adjacencyMatrix[i][j] != 0) {
                edges.push_back({i, {j, adjacencyMatrix[i][j]}});
            }
        }
    }
    return edges;
}

// Function to get the neighbors of a specific node
std::vector<size_t> Graph::getNeighbors(size_t node) const {
    std::vector<size_t> neighbors;
    if (node >= adjacencyMatrix.size()) {
        throw std::out_of_range("Node index out of range");
    }
    for (size_t i = 0; i < adjacencyMatrix[node].size(); ++i) {
        if (adjacencyMatrix[node][i] != 0) {
            neighbors.push_back(i);
        }
    }
    return neighbors;
}

// Function to get the weight of an edge between two nodes
int Graph::getEdgeWeight(size_t node1, size_t node2) const {
    if (node1 >= adjacencyMatrix.size() || node2 >= adjacencyMatrix.size()) {
        throw std::out_of_range("Node index out of range");
    }
    return adjacencyMatrix[node1][node2];
}

// Arithmetic operators
Graph Graph::operator+(const Graph& other) const {
    checkSameSize(other);
    std::vector<std::vector<int>> result = adjacencyMatrix;
    for (size_t i = 0; i < adjacencyMatrix.size(); ++i) {
        for (size_t j = 0; j < adjacencyMatrix[i].size(); ++j) {
            result[i][j] += other.adjacencyMatrix[i][j];
        }
    }
    return Graph(result);
}

Graph& Graph::operator+=(const Graph& other) {
    checkSameSize(other);
    for (size_t i = 0; i < adjacencyMatrix.size(); ++i) {
        for (size_t j = 0; j < adjacencyMatrix[i].size(); ++j) {
            adjacencyMatrix[i][j] += other.adjacencyMatrix[i][j];
        }
    }
    return *this;
}

Graph Graph::operator+() const {
    return *this;
}

Graph Graph::operator-(const Graph& other) const {
    checkSameSize(other);
    std::vector<std::vector<int>> result = adjacencyMatrix;
    for (size_t i = 0; i < adjacencyMatrix.size(); ++i) {
        for (size_t j = 0; j < adjacencyMatrix[i].size(); ++j) {
            result[i][j] -= other.adjacencyMatrix[i][j];
        }
    }
    return Graph(result);
}

Graph& Graph::operator-=(const Graph& other) {
    checkSameSize(other);
    for (size_t i = 0; i < adjacencyMatrix.size(); ++i) {
        for (size_t j = 0; j < adjacencyMatrix[i].size(); ++j) {
            adjacencyMatrix[i][j] -= other.adjacencyMatrix[i][j];
        }
    }
    return *this;
}

Graph Graph::operator-() const {
    std::vector<std::vector<int>> result = adjacencyMatrix;
    for (auto& row : result) {
        for (auto& elem : row) {
            elem = -elem;
        }
    }
    return Graph(result);
}

// Comparison operators
bool Graph::operator==(const Graph& other) const {
    return adjacencyMatrix == other.adjacencyMatrix;
}

bool Graph::operator!=(const Graph& other) const {
    return !(*this == other);
}

bool Graph::operator<(const Graph& other) const {
    if (adjacencyMatrix.size() != other.adjacencyMatrix.size()) {
        return adjacencyMatrix.size() < other.adjacencyMatrix.size();
    }
    return getEdgeCount() < other.getEdgeCount();
}

bool Graph::operator<=(const Graph& other) const {
    return *this < other || *this == other;
}

bool Graph::operator>(const Graph& other) const {
    return !(*this <= other);
}

bool Graph::operator>=(const Graph& other) const {
    return !(*this < other);
}

// Increment and decrement operators
Graph& Graph::operator++() {
    for (auto& row : adjacencyMatrix) {
        for (auto& elem : row) {
            ++elem;
        }
    }
    return *this;
}

Graph Graph::operator++(int) {
    Graph temp = *this;
    ++(*this);
    return temp;
}

Graph& Graph::operator--() {
    for (auto& row : adjacencyMatrix) {
        for (auto& elem : row) {
            --elem;
        }
    }
    return *this;
}

Graph Graph::operator--(int) {
    Graph temp = *this;
    --(*this);
    return temp;
}

// Scalar multiplication
Graph Graph::operator*(int scalar) const {
    std::vector<std::vector<int>> result = adjacencyMatrix;
    for (auto& row : result) {
        for (auto& elem : row) {
            elem *= scalar;
        }
    }
    return Graph(result);
}

// Graph multiplication
Graph Graph::operator*(const Graph& other) const {
    if (adjacencyMatrix.size() != other.adjacencyMatrix.size()) {
        throw std::invalid_argument("Graphs must be of the same size to multiply.");
    }

    std::vector<std::vector<int>> result(adjacencyMatrix.size(), std::vector<int>(adjacencyMatrix.size(), 0));
    for (size_t i = 0; i < adjacencyMatrix.size(); ++i) {
        for (size_t j = 0; j < adjacencyMatrix.size(); ++j) {
            for (size_t k = 0; k < adjacencyMatrix.size(); ++k) {
                result[i][j] += adjacencyMatrix[i][k] * other.adjacencyMatrix[k][j];
            }
        }
    }
    return Graph(result);
}

// Output operator
std::ostream& operator<<(std::ostream& os, const Graph& graph) {
    size_t vertexCount = graph.getNumberOfNodes();
    int edgeCount = graph.getEdgeCount();
    os << "Graph with " << vertexCount << " vertices and " << edgeCount << " edges.\n";
    for (const auto& row : graph.adjacencyMatrix) {
        for (const auto& elem : row) {
            os << elem << ' ';
        }
        os << '\n';
    }
    return os;
}

// Private helper functions
size_t Graph::getNumberOfNodes() const {
    return adjacencyMatrix.size();
}

int ariel::Graph::getEdgeCount() const {
    int edgeCount = 0;
    for (const auto& row : adjacencyMatrix) {
        for (const auto& elem : row) {
            if (elem != 0) {
                edgeCount++;
            }
        }
    }
    if (!getDirected()) {
        edgeCount /= 2;
    }
    return edgeCount;
}

void Graph::checkSameSize(const Graph& other) const {
    if (adjacencyMatrix.size() != other.adjacencyMatrix.size()) {
        throw std::invalid_argument("Graphs must be of the same size.");
    }
}
