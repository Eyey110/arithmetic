cmake_minimum_required(VERSION 3.9)
project(arithmetic)

set(CMAKE_CXX_STANDARD 11)

add_executable(arithmetic main.cpp array_utils.h log_utils.h search.h leetcode_array.h performance_utils.h sort.h MaxHeap.h BST.h leetcode_dp.h UnionFind.h Graph.h ReadGraph.h WeightedGraph.h MinHeap.h LazyPrimMST.h IndexMinHeap.h)