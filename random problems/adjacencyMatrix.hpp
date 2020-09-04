//
//  adjacencyMatrix.hpp
//  TestGraphs
//
//  Created by Ehiremen Ekore on 9/4/20.
//  Copyright © 2020 Ehiremen Ekore. All rights reserved.
//

#pragma once

#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <stack>

using namespace std;
// given an NxN adjacency matrix (of a graph), return the result of a bfs
vector<char> bfsAdjacencyMatrix (vector<vector<int>> input){
    queue<char> q;
    vector<char> out;
    
    int row = 0;
    
    // put all adjacencies of parent node on stack
    for (int k: input[0]) {
        if (k == 1) {
            q.push('A' + row);
            out.push_back('A' + row);
        }
        ++row;
    }
    
    while (!q.empty()){
        row = 0;
        for (int k: input[q.front() - 'A']) {
            if (k == 1){
                
                //if node not already seen, add it to the queue
                if (find(out.begin(), out.end(), 'A' + row) == out.end()) {
                    q.push('A' + row);
                    out.push_back('A' + row);
                }
            }
            ++row;
        }
        q.pop();
        if (out.size() == input.size()) break;
    }
    return out;
}

// ==============================================================================


// given an NxN adjacency matrix (of a graph), return the result of a dfs
vector<char> dfsAdjacencyMatrix (vector<vector<int>> input){
    stack<char> s;
    vector<char> out;
    
    int row = 0;
    
    // add first matched node to the stack and output vector
    for (int k: input[0]) {
        if (k == 1) {
            s.push('A' + row);
            out.push_back('A' + row);
            break;
        }
        ++row;
    }
    
    while (!s.empty()) {
        row = 0;
        for (int k: input[s.top() - 'A']) {
            if (k==1) { // potentially more depth
                
                // if item isn't already in the output vector, put it on top of stack
                // so it becomes out active node
                if (find(out.begin(), out.end(), 'A' + row) == out.end()) {
                    s.push('A' + row);
                    out.push_back('A' + row);
                    row = 0;
                }
            }
            ++row;
            
            // if checked every child of top of stack, pop the stack
            if (row == input.size()) {
                s.pop();
            }
        }
    }
    return out;
}
