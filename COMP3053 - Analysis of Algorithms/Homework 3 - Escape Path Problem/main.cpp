/**
 * James Pryor
 * COMP3053 Analysis of Algorithms
 * Homework #3 - Path Finding
 * 
 * main.cpp
 */

#include <string>
#include "pathFinder.h"

using namespace std;

int main(int argc, char** argv) {
    string path = "map.txt";    // Default input path.
    if(argv[1] != NULL) {       // Custom input path argument.
        path = argv[1];
    }

    pathFinder calc(path);
    calc.find();                // Calculate escape paths.
    calc.displayMap();          // Display Results.
        
    return 0;
}
