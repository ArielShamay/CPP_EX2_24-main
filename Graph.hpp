// Graph.hpp

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <utility>
#include <iostream>

namespace ariel {

    class Graph {
    private:
        bool directed;

        // Private helper functions
        void checkSameSize(const Graph& other) const;

    public:
        int getEdgeCount() const;
        std::vector<std::vector<int>> adjacencyMatrix;
        
        // Constructors
        Graph() = default;
        Graph(const std::vector<std::vector<int>>& matrix) { loadGraph(matrix); }

        // Graph functions
        void loadGraph(const std::vector<std::vector<int>>& matrix);
        void printGraph() const;
        bool isDirected() const;
        std::vector<std::pair<size_t, std::pair<size_t, int>>> getEdges() const;
        std::vector<std::size_t> getNeighbors(std::size_t node) const;
        int getEdgeWeight(size_t ver1, size_t ver2) const;

        // Inline functions
        bool getDirected() const { return this->directed; }
        std::size_t getNumberOfNodes() const { return adjacencyMatrix.size(); }
        bool isEdge(size_t from, size_t to) const { return adjacencyMatrix[from][to] != 0; }
        std::vector<std::vector<int>> getMatrix() const { return adjacencyMatrix; }

        // Arithmetic operators
        Graph operator+(const Graph& other) const;
        Graph& operator+=(const Graph& other);
        Graph operator+() const;
        Graph operator-(const Graph& other) const;
        Graph& operator-=(const Graph& other);
        Graph operator-() const;
        Graph operator*(int scalar) const;
        Graph& operator*=(int scalar); // הוספת הצהרת המפעיל *=
        Graph& operator/=(int scalar); // הוספת הצהרת המפעיל /=

        // Graph multiplication
        Graph operator*(const Graph& other) const;

        // Comparison operators
        bool operator==(const Graph& other) const;
        bool operator!=(const Graph& other) const;
        bool operator<(const Graph& other) const;
        bool operator<=(const Graph& other) const;
        bool operator>(const Graph& other) const;
        bool operator>=(const Graph& other) const;

        // Increment and decrement operators
        Graph& operator++();
        Graph operator++(int);
        Graph& operator--();
        Graph operator--(int);

        // Output operator
        friend std::ostream& operator<<(std::ostream& os, const Graph& graph);
    };

    using StartNode = size_t;
    using EndNode = size_t;

}

#endif // GRAPH_HPP
