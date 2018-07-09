//
// Created by Eyey on 2018/7/5.
//

#ifndef ARITHMETIC_WEIGHTEDGRAPH_H
#define ARITHMETIC_WEIGHTEDGRAPH_H

#include <iostream>
#include <vector>
#include <cassert>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

namespace WeightGraph {

    template<typename Weight>
    class Edge {
    private:
        int from, to;
        Weight weight;
    public:
        Edge(int from, int to, Weight weight) {
            this->from = from;
            this->to = to;
            this->weight = weight;
        }

        Edge() {

        }

        ~Edge() {

        }

        int v() {
            return from;
        }

        int w() {
            return to;
        }


        Weight wt() {
            return weight;
        }

        int other(int x) {
            assert(x == from || x == to);
            return x == from ? to : from;
        }

        friend ostream &operator<<(ostream &os, const Edge &e) {
            os << e.from << "-" << e.to << ": " << e.weight;
            return os;
        }

        bool operator<(Edge<Weight> &edge) {
            return this->weight < edge.weight;
        }

        bool operator>(Edge<Weight> &edge) {
            return this->weight > edge.weight;
        }

        bool operator<=(Edge<Weight> &edge) {
            return this->weight <= edge.weight;
        }

        bool operator>=(Edge<Weight> &edge) {
            return this->weight >= edge.weight;
        }

        bool operator==(Edge<Weight> &edge) {
            return this->weight == edge.weight;
        }
    };


    template<typename Weight>
    class DenseGraph {
    private:
        int n, m;
        bool directed;
        vector<vector<Edge<Weight> *>> g;
    public:
        DenseGraph(int n, bool directed) {
            assert(n > 0);
            this->n = n;
            this->m = 0;
            this->directed = directed;
            for (int i = 0; i < n; i++) {
                g.push_back(vector<Edge<Weight> *>(n, NULL));
            }
        }


        ~DenseGraph() {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    if (g[i][j] != NULL)
                        delete g[i][j];
        };


        int V() {
            return n;
        }

        int E() {
            return m;
        }


        bool hasEdge(int v, int w) {
            assert(v >= 0 && v < n);
            assert(w >= 0 && w < n);
            return g[v][w] != NULL;
        }

        void addEdge(int v, int w, Weight weight) {
            assert(v >= 0 && v < n);
            assert(w >= 0 && w < n);
            if (hasEdge(v, w)) {
                delete g[v][w];
                if (!directed)delete g[w][v];
                m--;
            }
            g[v][w] = new Edge<Weight>(v, w, weight);
            if (!directed) {
                g[w][v] = new Edge<Weight>(w, v, weight);
            }
        }

        void show() {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (g[i][j])
                        cout << g[i][j]->wt() << "\t";
                    else
                        cout << "NULL" << "\t";
                }
                cout << endl;
            }
        }


        class adjIterator {

        private:
            int index;
            int v;
            DenseGraph &G;

        public:
            adjIterator(DenseGraph &G, int v) : G(G) {
                this->index = 0;
                this->v = v;
            }

            Edge<Weight> *begin() {
                index = -1;
                return next();
            }

            Edge<Weight> *next() {
                vector<Edge<Weight> *> line = G.g[v];
                for (index += 1; index < line.size(); index++) {
                    if (line[index] != NULL)return line[index];
                }
                return NULL;
            }

            bool end() {
                return index >= G.g[v].size();
            }
        };
    };


//邻接表，稀疏图
    template<typename Weight>
    class SparseGraph {
    private:
        int n, m;
        bool directed;
        vector<vector<Edge<Weight> *>> g;
    public:
        SparseGraph(int n, bool directed) {
            this->n = n;
            this->m = 0;
            this->directed = directed;
            for (int i = 0; i < n; i++) {
                g.emplace_back();
            }
        }

        ~SparseGraph() {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < g[i].size(); j++) {
                    if (g[i][j] != NULL)
                        delete g[i][j];
                }
            }
        }


        void addEdge(int v, int w, Weight weight) {
            assert(v >= 0 && v < n);
            assert(w >= 0 && w < n);
            if (hasEdge(v, w))
                return;
            g[v].push_back(new Edge<Weight>(v, w, weight));
            if (v != w && !directed)
                g[w].push_back(new Edge<Weight>(w, v, weight));
            m++;
        }

        bool hasEdge(int v, int w) {
            assert(v >= 0 && v < n);
            for (Edge<Weight> *edge : g[v]) {
                if (edge->v() == v && edge->w() == w)
                    return true;
            }
            return false;
        }

        int V() {
            return n;
        }

        int E() {
            return m;
        }


        void show() {
            for (int i = 0; i < n; i++) {
                cout << "vertex " << i << ":\t";
                for (int j = 0; j < g[i].size(); j++) {
                    cout << g[i][j]->v() << "->" << g[i][j]->w() << ":" << g[i][j]->wt() << "\t";
                }
                cout << endl;
            }
        }


        class adjIterator {
        private:
            SparseGraph &G;
            int v;
            int index;
        public:
            adjIterator(SparseGraph &graph, int v) : G(graph) {
                this->v = v;
                this->index = 0;
            }

            Edge<Weight> *begin() {
                index = 0;
                if (!G.g[v].empty())
                    return G.g[v][index];
                return NULL;
            }

            Edge<Weight> *next() {
                index++;
                if (index < G.g[v].size())
                    return G.g[v][index];
                return NULL;
            }

            bool end() {
                return index >= G.g[v].size();
            }
        };
    };

    template<typename Graph, typename Weight>
    void readGraph(Graph &graph, const string &filename) {
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
            Weight weight;
            ss >> a >> b >> weight;
            assert(a >= 0 && a < V);
            assert(b >= 0 && b < V);
            graph.addEdge(a, b, weight);
        }
    }
}


#endif //ARITHMETIC_WEIGHTEDGRAPH_H
