/**
 * James Pryor
 * COMP3053 Analysis of Algorithms
 * Homework #2 - Eight Queens
 * 
 * main.cpp
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "nQueen.h"

using namespace std;

int main(int argc, char** argv){
    
    // Accepts a single parameter on execution, the size of the board.
    int n;
    if(argv[1] != NULL) {
        n = atoi(argv[1]);
        if(n > 27) {
            cout << "Try a number less than 20." << endl;
            return 0;
        }
    } else {
        n = 8;
    }
    
    // Start time.
    clock_t start, end;
    start = clock();
    
    // Create nQueens class and begin solving.
    nQueen solutions(n);
    solutions.solve();
    
    // End time and output results.
    end = clock();
    cout << endl << "Found " << solutions.solutions << " for " << n << "x" << n << " board";
    cout << " in " << ((float)end - start) / CLOCKS_PER_SEC << " seconds." << endl << endl;
    
    return 0;
}
