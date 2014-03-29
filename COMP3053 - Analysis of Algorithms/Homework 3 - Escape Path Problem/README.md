Homework #3 - Escape Path Problem
=================================
James Pryor  
COMP3053 Analysis of Algorithms  

[online][git]


Assignment Description
----------------------
Design an algorithm that identifies the external gaps in a map. An external gap means that there is 
an outlet reaching the outside of the map. You may imagine that these gaps are rivers that reach a 
boundary of a map, while an internal gap cannot reach the outside of the map. The following is an 
example where all red gaps are external gaps, while the green one is internal. 

![Example Image][img]

You need to write a C++ program to implement your algorithm and test a case using the provided text 
file as an input map. The file consists of 1s and 0s, where 1 means there is a gap at the current 
location, and 0 means no gap. Your program should identify all external gaps, and mark them using 
number 2s.  Do NOT change the values of internal gaps.

input:  

    0 0 0 0 0 0 0 1 0 0 0 0
    1 1 0 1 1 0 0 1 0 0 0 0
    0 1 1 1 0 0 0 1 1 1 0 0
    0 0 0 0 0 0 0 0 0 1 0 0
    0 0 0 0 1 1 0 0 1 1 0 0
    0 0 0 0 1 1 0 0 1 0 0 0
    0 0 0 0 0 0 0 0 0 0 0 0
    0 1 0 0 0 0 0 1 1 0 0 0
    0 1 0 0 0 0 0 0 1 1 1 0
    0 0 0 0 0 0 0 0 0 0 1 1
    0 0 0 1 1 1 1 1 0 0 0 0
    0 0 0 0 0 0 0 1 0 0 0 0

Expected Output:  

    0 0 0 0 0 0 0 2 0 0 0 0
    2 2 0 2 2 0 0 2 0 0 0 0
    0 2 2 2 0 0 0 2 2 2 0 0
    0 0 0 0 0 0 0 0 0 2 0 0
    0 0 0 0 1 1 0 0 2 2 0 0
    0 0 0 0 1 1 0 0 2 0 0 0
    0 0 0 0 0 0 0 0 0 0 0 0
    0 1 0 0 0 0 0 2 2 0 0 0
    0 1 0 0 0 0 0 0 2 2 2 0
    0 0 0 0 0 0 0 0 0 0 2 2
    0 0 0 2 2 2 2 2 0 0 0 0
    0 0 0 0 0 0 0 2 0 0 0 0


Solution
--------
### Compiling
From the Linux command line try something like:

    g++ -o pathFinder.exe main.cpp pathFinder.cpp

there is no make file for this.

Tested in Windows by copying and pasting `main.cpp`, `pathFinder.cpp`, and `pathFinder.h` into a new
Visual Studios 2010 project.

### Usage
The solution accepts a file as it's input. By default it looks for "map.txt" in the executable's 
directory, but the first argument can be a path. For example:

    pathFinder.exe c:\path\to\my\awesome_map.txt

or

    pathFinder.exe different_map.txt

The input map does not have to be square. Each row doesn't even have to be the same length, but 
short rows will be filled in with zero's to make the map a rectangle. Numbers other than 1 are 
changed to a 1, letters came out as zeros in testing (but this is not guaranteed). For best results
stick with zeros and ones. For example:

    0 1 0 0 0
    0 7 0
    a 0 0 1 
    0

Will become:

    0 1 0 0 0
    0 1 0 0 0
    0 0 0 1 0
    0 0 0 0 0

Paths will be figured according to rectangular maps, so the 1 in line three will be treated as if it
is not touching a map edge. The 1 in the first and second row will change to a 2 as expected. The 
results are displayed in the console.

There are example input maps and result maps in the maps folder.


[img]: docs/example.jpg
[git]: https://github.com/deplicator/assignments/tree/master/COMP3053%20-%20Analysis%20of%20Algorithms/Homework%203%20-%20Escape%20Path%20Problem
