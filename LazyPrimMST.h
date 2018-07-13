//
// Created by Eyey on 2018/7/13.
//

#ifndef ARITHMETIC_LAZYPRIMMST_H
#define ARITHMETIC_LAZYPRIMMST_H

#include "MinHeap.h"
#include "WeightedGraph.h"


using namespace std;
using namespace WeightGraph;


template<typename Graph, typename Weight>
class LazyPrimMST {

private:
    Graph &G;
    MinHeap<Edge<Weight>> pq;
    bool *marked;
    vector<Edge<Weight>> mst;
    Weight mstWeight;
    // 访问节点v
    void visit(int v){

        assert( !marked[v] );
        marked[v] = true;

        // 将和节点v相连接的所有未访问的边放入最小堆中
        typename Graph::adjIterator adj(G,v);
        for( Edge<Weight>* e = adj.begin() ; !adj.end() ; e = adj.next() )
            if( !marked[e->other(v)] )
                pq.insert(*e);
    }

public:

    LazyPrimMST(Graph &graph) : G(graph), pq(MinHeap<Edge<Weight>>(graph.E())) {
        marked = new bool[G.V()];
        for (int i = 0; i < G.V(); i++)
            marked[i] = false;
        mst.clear();
        visit(0);
        while (!pq.isEmpty()) {
            Edge<Weight> edge = pq.extractMin();
            if (marked[edge.v()] && marked[edge.w()])
                continue;
            mst.push_back(edge);
            if (!marked[edge.v()])
                visit(edge.v());
            else
                visit(edge.w());
        }

        if (!mst.empty()) {
            mstWeight = mst[0].wt();
            for (int i = 1; i < mst.size(); i++) {
                mstWeight += mst[i].wt();
            }
        }

    }

    ~LazyPrimMST() {
        delete[] marked;
    }

    vector<Edge<Weight>> mstEdges() {
        return mst;
    }


    Weight result() {
        return mstWeight;
    }
};


#endif //ARITHMETIC_LAZYPRIMMST_H
