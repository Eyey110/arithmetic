//
// Created by Eyey on 2018/7/4.
//

#ifndef ARITHMETIC_READGRAPH_H
#define ARITHMETIC_READGRAPH_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cassert>
#include "Graph.h"


using namespace std;


class ReadGraph {
public:
    ReadGraph(Graph &graph, const string &filename) {
        ifstream file(filename);
        string line;
        int V, E;

        assert(file.is_open());
        assert(getline(file, line));
        stringstream ss(line);
        ss >> V >> E;

        assert(V == graph.V());
        for (int i = 0; i < E; i++) {
            assert(getline(file, line));
            stringstream ss(line);
            int a, b;
            ss >> a >> b;
            assert(a >= 0 && a < V);
            assert(b >= 0 && b < V);
            graph.addEdge(a, b);
        }
    }
};


#endif //ARITHMETIC_READGRAPH_H
