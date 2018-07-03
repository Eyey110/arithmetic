//
// Created by Eyey on 2018/7/3.
//

#ifndef ARITHMETIC_UNIONFIND_H
#define ARITHMETIC_UNIONFIND_H


#include <cassert>

/*
 * 并查集数组实现
 */
class UnionFindArray {
private:
    int *id;
    int count;
public:
    UnionFindArray(int n) {
        count = n;
        id = new int[n];
        for (int i = 0; i < n; i++) {
            id[i] = i;
        }
    }

    ~UnionFindArray() {
        delete[] id;
    }


    int find(int p) {
        assert(p >= 0 && p < count);
        return id[p];
    }

    bool isConnected(int p, int q) {
        return find(p) == find(q);
    }

    void unionElement(int p, int q) {
        int pID = find(p);
        int qID = find(q);
        if (pID != qID) {
            for (int i = 0; i < count; i++) {
                if (id[i] == pID)
                    id[i] = qID;
            }
        }
    }

};


/**
 * 并查集树实现,size优化
 */
class UnionFindTree {
private:
    int *parent;
    int *sz;//sz[i]表示以i为根的集合元素个数
    int count;

public:
    UnionFindTree(int count) : count(count) {
        parent = new int[count];
        sz = new int[count];
        for (int i = 0; i < count; i++) {
            parent[i] = i;
            sz[i] = 1;
        }
    }

    virtual ~UnionFindTree() {
        delete[] parent;
        delete[] sz;
    }

    int find(int p) {
        assert(p >= 0 & p < count);
        while (p != parent[p]) {
            p = parent[p];
        }
        return p;
    }

    bool isConnect(int p, int q) {
        return find(p) == find(q);
    }

    void unionElement(int p, int q) {
        int pRoot = find(p);
        int qRoot = find(q);
        if (pRoot != qRoot) {
            if (sz[pRoot] < sz[qRoot]) {
                parent[pRoot] = qRoot;
                sz[qRoot] += sz[pRoot];
            } else {
                parent[qRoot] = pRoot;
                sz[pRoot] += sz[qRoot];
            }
        }
    }
};

/**
 * 并查集树实现,rank优化
 */
class UnionFindRank {
private:
    int *parent;
    int *rank;//rank[i]表示以i为根的集合树高度
    int count;

public:
    UnionFindRank(int count) : count(count) {
        parent = new int[count];
        rank = new int[count];
        for (int i = 0; i < count; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    virtual ~UnionFindRank() {
        delete[] parent;
        delete[] rank;
    }

    int find(int p) {
        assert(p >= 0 & p < count);
        while (p != parent[p]) {
            p = parent[p];
        }
        return p;
    }

    bool isConnect(int p, int q) {
        return find(p) == find(q);
    }

    void unionElement(int p, int q) {
        int pRoot = find(p);
        int qRoot = find(q);
        if (pRoot != qRoot) {
            if (rank[pRoot] < rank[qRoot]) {
                parent[pRoot] = qRoot;
            } else {
                parent[qRoot] = pRoot;
                if (rank[pRoot] == rank[qRoot]) {
                    rank[pRoot]++;
                }
            }
        }
    }
};

/**
 * 并查集树实现,路劲压缩优化
 */
class UnionFindCompress {
private:
    int *parent;
    int *rank;//rank[i]表示以i为根的集合树高度
    int count;

public:
    UnionFindCompress(int count) : count(count) {
        parent = new int[count];
        rank = new int[count];
        for (int i = 0; i < count; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    virtual ~UnionFindCompress() {
        delete[] parent;
        delete[] rank;
    }

    int find(int p) {
        assert(p >= 0 & p < count);
//        while (p != parent[p]) {
//            parent[p] = parent[parent[p]];
//            p = parent[p];
//        }
        if(p!=parent[p]){
            parent[p] = find(parent[p]);
        }
        return p;
    }

    bool isConnect(int p, int q) {
        return find(p) == find(q);
    }

    void unionElement(int p, int q) {
        int pRoot = find(p);
        int qRoot = find(q);
        if (pRoot != qRoot) {
            if (rank[pRoot] < rank[qRoot]) {
                parent[pRoot] = qRoot;
            } else {
                parent[qRoot] = pRoot;
                if (rank[pRoot] == rank[qRoot]) {
                    rank[pRoot]++;
                }
            }
        }
    }
};


#endif //ARITHMETIC_UNIONFIND_H
