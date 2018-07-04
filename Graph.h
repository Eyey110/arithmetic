//
// Created by Eyey on 2018/7/3.
//

#ifndef ARITHMETIC_DENSEGRAPH_H
#define ARITHMETIC_DENSEGRAPH_H

#include <cassert>
#include <vector>
#include <stack>

using namespace std;

class Graph {
protected:
    int n, m;
    bool directed;

public:

    Graph(int n, bool directed) : n(n), directed(directed) {
        this->m = 0;

    }

    virtual int V() { return n; }

    virtual int E() { return m; }

    virtual void addEdge(int v, int w) =0;

    virtual bool hasEdge(int v, int w) =0;

    virtual void show() = 0;

};


//邻接矩阵，稠密图
class DenseGraph : public Graph {

private:
    vector<vector<bool>> g;
public:
    DenseGraph(int n, bool directed) : Graph(n, directed) {
        for (int i = 0; i < n; i++) {
            g.emplace_back(n, false);
        }
    }

    virtual ~DenseGraph() = default;

    void addEdge(int v, int w) override {
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);
        if (hasEdge(v, w))
            return;
        g[v][w] = true;
        if (!directed)
            g[w][v] = true;
        m++;
    }

    bool hasEdge(int v, int w) override {
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);
        return g[v][w];
    }


    void show() override {
        for (int i = 0; i < n; i++) {
            cout << "vertex " << i << ":\t";
            for (int j = 0; j < g[i].size(); j++) {
                if (g[i][j]) {
                    cout << j << "\t";
                }
            }
            cout << endl;
        }
    }

    class adjIterator {
    private:
        DenseGraph &G;
        int v;
        int index;
    public:
        adjIterator(DenseGraph &graph, int v) : G(graph) {
            this->v = v;
            this->index = -1;
        }

        int begin() {
            index = -1;
            return next();
        }

        int next() {
            vector<bool> line = G.g[v];
            for (index += 1; index < line.size(); index++) {
                if (line[index])return index;
            }
            return -1;
        }

        bool end() {
            return index >= G.g[v].size();
        }
    };
};


//邻接表，稀疏图
class SparseGraph : public Graph {
private:
    vector<vector<int>> g;
public:
    SparseGraph(int n, bool directed) : Graph(n, directed) {
        for (int i = 0; i < n; i++) {
            g.emplace_back();
        }
    }

    virtual ~SparseGraph() = default;


    void addEdge(int v, int w) override {
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);
//        if (hasEdge(v, w))
//            return;
        g[v].push_back(w);
        if (v != w && !directed)
            g[w].push_back(v);
        m++;
    }

    bool hasEdge(int v, int w) override {
        assert(v >= 0 && v < n);
        for (int i : g[v]) {
            if (i == w)
                return true;
        }
        return false;
    }


    void show() override {
        for (int i = 0; i < n; i++) {
            cout << "vertex " << i << ":\t";
            for (int j = 0; j < g[i].size(); j++) {
                cout << g[i][j] << "\t";
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

        int begin() {
            index = 0;
            if (!G.g[v].empty())
                return G.g[v][index];
            return -1;
        }

        int next() {
            index++;
            if (index < G.g[v].size())
                return G.g[v][index];
            return -1;
        }

        bool end() {
            return index >= G.g[v].size();
        }
    };
};

template<typename Graph>
class Component {
private:
    Graph &G;
    bool *visited;
    int ccount;
    int *id;

    void dfs(int v) {
        visited[v] = true;
        id[v] = ccount;
        typename Graph::adjIterator adj(G, v);
        for (int i = adj.begin(); !adj.end(); i = adj.next()) {
            if (!visited[i]) {
                dfs(i);
            }
        }
    }

public:
    Component(Graph &graph) : G(graph) {
        visited = new bool[G.V()];
        id = new int[G.V()];
        ccount = 0;
        for (int i = 0; i < G.V(); i++) {
            visited[i] = false;
            id[i] = -1;
        }

        for (int i = 0; i < G.V(); i++) {
            if (!visited[i]) {
                dfs(i);
                ccount++;
            }
        }
    }

    int count() {
        return ccount;
    }


    bool isConnect(int v, int w) {
        assert(v >= 0 && v < G.v());
        assert(w >= 0 && w < G.v());
        return id[v] == id[w];
    }

    ~Component() {
        delete[] visited;
        delete[] id;
    }
};


template<typename Graph>
class Path {
private:
    Graph &G;
    bool *visited;
    int start;
    int *from;

    void dfs(int v) {
        visited[v] = true;
        typename Graph::adjIterator adj(G, v);
        for (int i = adj.begin(); !adj.end(); i = adj.next()) {
            if (!visited[i]) {
                from[i] = v;
                dfs(i);
            }
        }
    }

public:
    Path(Graph &G, int s) : G(G) {
        assert(s >= 0 && s < G.V());
        visited = new bool[G.V()];
        from = new int[G.V()];
        this->start = s;
        for (int i = 0; i < G.V(); i++) {
            visited[i] = false;
            from[i] = -1;
        }

        dfs(s);
    }


    ~Path() {
        delete[] visited;
        delete[] from;
    }


    bool hasPath(int w) {
        assert(w >= 0 && w < G.V());
        return visited[w];
    }

    void path(int w, vector<int> &vec) {
        assert(hasPath(w));
        stack<int> s;
        while (w != -1) {
            s.push(w);
            w = from[w];
        }
        while (!s.empty()) {
            vec.push_back(s.top());
            s.pop();
        }
    }

    void showPath(int w) {

        assert(hasPath(w));

        vector<int> vec;
        path(w, vec);
        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i];
            if (i == vec.size() - 1)
                cout << endl;
            else
                cout << " -> ";
        }
    }
};


#endif //ARITHMETIC_DENSEGRAPH_H
