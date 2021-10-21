# Breadth first search

## Introduction

Breadth first search is a graph traversal algorithm that starts traversing the graph from root node and explores all the neighbouring nodes. Then, it selects the nearest node and explore all the unexplored nodes. The algorithm follows the same process for each of the nearest node until it finds the goal.

## Algorithm

Step 1: SET STATUS = 1 (ready state) <br>
&emsp;&emsp; for each node in G <br>
Step 2: Enqueue the starting node A <br>
&emsp;&emsp; and set its STATUS = 2 <br>
&emsp;&emsp; (waiting state) <br>
Step 3: Repeat Steps 4 and 5 until <br>
&emsp;&emsp; QUEUE is empty <br>
Step 4: Dequeue a node N. Process it <br>
&emsp;&emsp; and set its STATUS = 3 <br>
&emsp;&emsp; (processed state). <br>
Step 5: Enqueue all the neighbours of <br>
&emsp;&emsp; N that are in the ready state <br>
&emsp;&emsp; (whose STATUS = 1) and set <br>
&emsp;&emsp; their STATUS = 2 <br>
&emsp;&emsp; (waiting state) <br>
[END OF LOOP] <br>
Step 6: EXIT <br>

<br>[Learn more about Breadth First Search Algorithm](https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/)

<br>![alt text](../../doc-assets/imgs/gr-bfsrh/bfs.jpg)

## Implementations

Below are some examples of how the Breadth First Search Algorithm is implemented using different programming languages.

-   [C](https://github.com/FOSS-UCSC/FOSSALGO/blob/master/algorithms/gr-bfsrh/c/bfs.c)
-   [C#](https://github.com/FOSS-UCSC/FOSSALGO/blob/master/algorithms/gr-bfsrh/csharp/BreadthFirst.cs)
-   [Java](https://github.com/FOSS-UCSC/FOSSALGO/blob/master/algorithms/gr-bfsrh/java/BreadthFirstSearch.java)
-   [Python 3](https://github.com/FOSS-UCSC/FOSSALGO/blob/master/algorithms/gr-bfsrh/python3/breadth_first_search.py)
