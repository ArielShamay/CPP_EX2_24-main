# MatrixGraphsOperator - Advanced Graph Operations in C++

### Ariel Shamay
**Email:** [arielsh49@gmail.com](mailto:arielsh49@gmail.com)  
**LinkedIn:** [https://www.linkedin.com/in/ariel-shamay-78011a2b0](https://www.linkedin.com/in/ariel-shamay-78011a2b0)

---

## Project Overview

**MatrixGraphsOperator** extends previous implementations of adjacency matrix-based graphs by introducing extensive operator overloading, enabling arithmetic and logical operations directly on graph structures. This approach allows intuitive and mathematically precise manipulations, such as addition, subtraction, scalar multiplication, and graph comparisons, alongside traditional graph algorithms.

---

## Main Features

- **Adjacency Matrix Representation**: Efficient and clear representation of graphs using adjacency matrices.
- **Operator Overloading**: Includes arithmetic operators (`+`, `-`, `+=`, `-=`), comparison operators (`==`, `!=`, `<`, `<=`, `>`, `>=`), increment/decrement operators (`++`, `--`), and multiplication operations.
- **Integration with Graph Algorithms**: Supports algorithms for connectivity, cycle detection, bipartiteness checks, and more.
- **Robust Exception Handling**: Error handling for invalid operations, such as incompatible matrix dimensions.
- **Clear Output Operator**: Provides clear and readable representations of graphs.

---

## Project Structure

- `Graph.cpp` / `Graph.hpp`: Implementation of graph structures and overloaded operators.
- `Algorithms.cpp` / `Algorithms.hpp`: Common graph algorithm implementations (connectivity, shortest paths, cycles).
- `Demo.cpp`: Demonstrates functionalities and operator usage.
- `Test.cpp`: Contains automated unit tests to ensure correctness.

---

## Setup Instructions

### Requirements
- C++ compiler (`g++` recommended)

### Installation

Clone the repository:

```bash
git clone <repository_url>
cd MatrixGraphsOperator
```

### Compile Project

Compile using the provided Makefile:

```bash
make
```

### Running the Application

Execute the demonstration:

```bash
./demo
```

### Running Tests

Run automated unit tests:

```bash
make test
./test
```

---

## Technologies & Tools

- **C++**
- **Doctest** (Unit testing framework)
- **Makefile** (Build automation)

---

## Notes

Ensure your development environment includes a compatible C++ compiler and standard libraries for successful compilation and execution.

