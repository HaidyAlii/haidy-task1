# haidy-task1
# Path Planning with BFS and DFS

This repository contains Python code implementing the Breadth-First Search (BFS) and Depth-First Search (DFS) algorithms for path planning on a 5x5 grid.

## Problem Description

The grid is represented as a 2D array with obstacles marked as -1. The start point is at (3,0), and the goal point is at (0,4). Obstacles are present at the following positions: (0,0), (2,0), (4,0), (1,4), and (3,4).

## BFS Algorithm

Breadth-First Search is an algorithm that explores the grid layer by layer, prioritizing cells based on their proximity to the start point. The priority order is right, up, left, and down. The algorithm continues to explore each cell, updating priorities, until the goal is reached. The final result is the shortest path from the start to the goal.

### BFS :

1. Start at (3,0)
2. Explore (3,1) - Right
3. Explore (2,1) - Up, (3,2) - Right
4. Explore (4,1) - Down
5. Repeat for the next cells until the goal (0,4) is reached.
   ![image](https://github.com/HaidyAlii/haidy-task1/assets/153645844/52936b2f-6ab0-4d3b-88b4-2db400c0c407)


## DFS Algorithm

Depth-First Search is an algorithm that explores the grid by traversing as far as possible along each branch before backtracking. The priority order is the same as BFS: right, up, left, and down ,The algorthim for the DFs from the start point the prority will be right which is the cell (3,1), for the cell there is prority which is uo so it will go up to the last cell which is (0,1) ,then the prority will be right to the last cell which is (0,4) ,this cell is the goal 
In the end when reach the goal will get the shortest path which is (3,0) (3,1) (2,1) (1,1) (0,1) (0,2) (0,3) (0,4), The algorithm continues to explore each branch until the goal is reached. The final result is the path from the start to the goal.

### DFS :

1. Start at (3,0)
2. Explore (3,1) - Right
3. Explore (2,1) - Up
4. Explore (3,2) - Right
5. Explore (2,2) - Up, (1,2) - Left
6. Repeat for the next cells until the goal (0,4) is reached.
   ![image](https://github.com/HaidyAlii/haidy-task1/assets/153645844/41a8ed56-176d-4631-94b5-1e3a89e994f8)


## Usage

To run the code, you can customize the obstacle positions, start point, and goal point in the main.py file.

# Specify grid and obstacles
grid = [
    [0, 2, 3, 4, 5],
    [6, 7, 8, 9, -1],
    [-1, 12, 13, 14, 15],
    [16, 17, 18, 19, -1],
    [-1, 22, 23, 24, 25]
]

# Specify start and goal points
start = (3, 0)
goal = (0, 4)

# Run BFS algorithm
shortest_path_bfs = bfs(grid, start, goal)
print("BFS Shortest Path:", shortest_path_bfs)

# Run DFS algorithm
path_dfs = dfs(grid, start, goal)
print("DFS Path:", path_dfs)

### the solution by handwritten
![image](https://github.com/HaidyAlii/haidy-task1/assets/153645844/c3494d16-b112-4f5c-ad28-7f4566b22f66)
