/**
 * James Pryor
 * COMP3053 Analysis of Algorithms
 * Homework #3 - Path Finding
 * 
 * pathFinder.h
 */

#include <string>
#include <vector>

#ifndef PATHFINDER_H
#define PATHFINDER_H

class pathFinder {
    private:
        std::vector< std::vector<int> > inputMap;  // Vector of vectors that represents input map.
        std::vector< std::vector<int> > outputMap; // Vector of vectors that represents output map.
        std::vector< std::vector<int> > visited;   // Locations visited.
        int mapHeight;                             // Number of rows.
        int mapWidth;                              // Number of column.

    public:
        pathFinder(std::string path);              // Constructor validates input and sets up.
        void find();                               // Starts solving.
        void findEdges();                          // First part of path finding.
        void findMore(int x, int y);               // Second part of path finding.
        void displayMap(bool input = false);       // Display results.
};

#endif
