# Interval Graph Coloring

This project implements a greedy algorithm for coloring interval graphs in C. The program reads a set of intervals, sorts them, and then applies a greedy coloring algorithm to determine the chromatic number of the graph. Additionally, it calculates the maximum and minimum degrees of the graph and its complement.

## Files

- `main.c`: Contains the main function and the implementation of the greedy coloring algorithm.

## Functions

- `void swap(interval *a, interval *b)`: Swaps two intervals.
- `void sort_graph(interval *arr, int k)`: Sorts the intervals based on their starting points.
- `int color_graph(interval *arr, int *color, int k)`: Colors the graph and returns the chromatic number.
- `Degrees F_Edges(interval *arr, int *Degs, int *Edges, Degrees MMDegs, int k)`: Finds the edges and calculates the maximum and minimum degrees.
- `void Opt_Coloring(interval *arr, int colorMax, int *color, int k)`: Prints the optimal coloring of the graph.
- `void IPrint(interval *arr, int k)`: Reads and prints the intervals.
- `void GreedyColoring()`: Main function that drives the greedy coloring algorithm.

## Usage

1. Compile the code using Visual Studio 2017 or any compatible C compiler.
2. Run the executable.
3. Input the number of intervals.
4. Input the intervals when prompted.
5. The program will output the edges, maximum and minimum degrees, chromatic number, and optimal coloring of the graph.

## Example

```
Input number of intervals:
3
Input Interval number 1:
1 3
Input Interval number 2:
2 5
Input Interval number 3:
4 6
The interval family is:
[1,3] [2,5] [4,6] 
G Edges=3
Max Degree of G=2
min Degree of G=1
Chromatic number of G=3
G's compliment Edges=0
Max Degree of G's compliment=1
Min Degree of G's compliment=0
Optional coloring: {[1,3]} = 1,  {[2,5]} = 2,  {[4,6]} = 3
```

## Notes

- The program uses dynamic memory allocation for arrays. Make sure to free the allocated memory if you modify the code.
- The program is designed to run on Windows systems due to the use of `system("pause")`. For other systems, you may need to remove or replace this line.

## License

This project is licensed under the MIT License. See the LICENSE file for details.
