# Rubik Cube
C++ heuristic search based program that takes initial and final configurations of cube and outputs minimum number of moves (i.e. 90' turns of faces) needed to transform initial state into final state

Program is provided with a file containing a set of initial and final configuration pairs and a limit L on the number of moves allowed. For each pair of configurations and limit, program generates a set of at most L valid moves needed to transform the initial state into the final state or it informs the user that no such sequence of moves exists.

File Format: The first line of the file contains a single integer giving a number n, the total number of puzzles in the file. The next 3n lines of the file contains the n puzzles with each complete puzzle specified on three consecutive lines of the file. The first line of each puzzle contains the initial configuration(a space separated list of 54 digits) and the second line contains the final configuration and the third line contains the value of L for the puzzle. A complete configuration of a puzzle consists of 54 space separated digits which give the color information on each of the six sides of the cube. A color on each of the nine cubes on a given side is a digit from the set {1, 2, 3, 4, ,5 ,6}. The first 9 digits of these 54 digits specifying the colors of the 9 cubes faces on the front side (left-right and top-bottom), the next 9 numbers specifying the color information on the back side (right-left, top-bottom) and then comes the color information of top, bottom, left and right sides.

# Contributors
Ayesha Tahreem Aamir, Mahnoor Fatima
