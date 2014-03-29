/**
 * James Pryor
 * COMP3053 Analysis of Algorithms
 * Homework #3 - Path Finding
 * 
 * pathFinder.cpp
 */

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "pathFinder.h"

using namespace std;

/**
 * Constructor - lots of comments because some of this is new to me.
 * Parameter path is the location of the input file.
 */
pathFinder::pathFinder(string path) {
    // Convert input file into a stringstream.
    stringstream mapBuffer;            // Buffer to hold file contents.
    ifstream mapFile (path.c_str());   // Open input file.
    mapBuffer << mapFile.rdbuf();      // Store all of file contents into buffer.
    
    //Close input file, or display error message.
    if(mapFile.is_open()) {
        mapFile.close();
    } else {
        cout << "File at path '" << path << "' was not found or cannot be opened." << endl;
        exit(0);
    }

    // Convert stringstream to vector of vectors.
    string findRow;
    string findElem;
    int countY = 1;                 // Counter for each row (y-axis is the map height).
    int countX = 1;                 // Counter for each element in rows (x-axis is the map width).

    while(getline(mapBuffer, findRow, '\n')) { // Separate rows by line break.
        stringstream streamRow(findRow);        // Stream of each row.
        vector<int> newRow;                     // Create vector for each row.
        countX = 1;                             // Restart element count with each row.
        
        while(getline(streamRow, findElem, ' ')) {      // Separate elements in row by space.
            newRow.push_back(atoi(findElem.c_str()));   // Push element into row vector.
            
            if(countX > mapWidth) { // If this is the longest row found so far,
                mapWidth = countX;  // set it as the over all map width.
            }
            countX++;               // Increment element count for this row.
        }
        inputMap.push_back(newRow); // Push completed row to map vector.
        mapHeight = countY;         // Set map height to current row.
        countY++;                   // Increment row counter.
    }
    
    // Clean up irregular map, make rectangular, force all numbers to be 1.
    for(int i = 0; i < mapHeight; i++) {
        inputMap[i].resize(mapWidth);
        for(int j = 0; j < mapWidth; j++) {
            if(inputMap[i][j]) {
                inputMap[i][j] = 1;
            }
        }
    }
    
    // Set up blank visited vector.
    for(int i = 0; i < mapHeight; i++) {
        vector<int> newRow;
        for(int j = 0; j < mapWidth; j++) {
            newRow.push_back(0);
        }
        visited.push_back(newRow);
    }
    
    outputMap = inputMap; // Copy map.
}

/**
 * A convenience call that kicks off paths to edges search. 
 */
void pathFinder::find() {
    findEdges();
}

/**
 * Find ones on the outer edges of the map.
 */
void pathFinder::findEdges() {
    //look at four edges of maps, change any numbers found to 2--these are start points 
    for(int i = 0; i < mapWidth; i++) {
        //first row
        if(outputMap[0][i]) {
            outputMap[0][i] = 2;
            findMore(0, i);
        }
        
        //last row
        if(outputMap[mapHeight-1][i]) {
            outputMap[mapHeight-1][i] = 2;
            findMore(mapHeight-1, i);
        }
    }
    for(int i = 0; i < mapHeight; i++) {
        //first column
        if(outputMap[i][0]) {
            outputMap[i][0] = 2;
            findMore(i, 0);
        }
        
        //last column
        if(outputMap[i][mapWidth-1]) {
            outputMap[i][mapWidth-1] = 2;
            findMore(i, mapWidth-1);
        }
    }
}

/**
 * Recursively find one's orthogonal to two's, makes use of visited vectors.
 * Parameters x and y are the start location (they are backwards from expected use but work).
 */
void pathFinder::findMore(int x, int y) {
    visited[x][y] = 1;
    if(x+1 < mapHeight && y+1 < mapWidth){
        // Check one to right.
        if(outputMap[x+1][y] && !visited[x+1][y]) {
            outputMap[x+1][y] = 2;
            findMore(x+1, y);
        }
        // Check one below.
        if(outputMap[x][y+1] && !visited[x][y+1]) {
            outputMap[x][y+1] = 2;
            findMore(x, y+1);
        }
    }
    
    if(x-1 > 0 && y-1 > 0){
        // Check one to left.
        if(outputMap[x-1][y] && !visited[x-1][y]) {
            outputMap[x-1][y] = 2;
            findMore(x-1, y);
        }
        // Check one above.
        if(outputMap[x][y-1] && !visited[x][y-1]) {
            outputMap[x][y-1] = 2;
            findMore(x, y-1);
        }
    }
}

/**
 * Creates a representation of map in console.
 * If input is set to true it will display input map instead of output map.
 */
void pathFinder::displayMap(bool input) {
    cout << endl;
    int rowLength;
    for(int i = 0; i < mapHeight; i++) {
        rowLength = inputMap[i].size();
        for(int j = 0; j < rowLength; j++) {
            if(input) {
                cout << inputMap[i][j] << ' ';
            } else {
                cout << outputMap[i][j] << ' ';
            }
        }
        cout << endl;
    }
    cout << endl;
}
