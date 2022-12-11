# Overview of Algorithms
## Breadth-First Search (BFS)
In our project, the BFS algorithm takes in an unordered map of all vertices in the graph, as input, and is used to visit all vertices in the graph from a defined start vertex.
<br>
In particular, this algorithm utilizes a queue to keep track of all vertices that need to be visited. Additionally, it was implemented using *GraphTraversalIterator*, where we defined *operator++*, *operator!=*, and _operator*_, similar to mp_traversals. To keep track of the nodes visited, we used a simple vector of strings. The runtime of our algorithm is **O(m+n)**, where n is the number of nodes and m is the number of edges.
<br>
To test this algorithm, we checked that our implementation (1) maintains a breadth-first ordering and (2) adds vertices to the queue correctly. For more information on these tests, please refer to tests.cpp in the tests directory.

## Depth-First Search (DFS)
Similar to BFS, the DFS algorithm also utilizes an unordered map of vertices, or nodes, as input to visit all vertices in the graph. However, in contrast to BFS, the DFS algorithm uses a stack to keep track of all nodes that need to be visited. This algorithm was also implemented using *GraphTraversalIterator*, and a vector of strings is used to record visited nodes. This algorithm’s runtime is also **O(m+n)**.
<br>
In order to test this algorithm, we checked that our implementation (1) maintains a depth-first ordering and (2) always ensures that the deepest vertex is on the top of the stack. These test cases are also defined in tests.cpp.

## Dijkstra's Algorithm
Dijkstra’s algorithm is used to return the shortest path between two given vertices of a graph. The algorithm makes use of a priority queue. In our project, this algorithm was applied to an unweighted graph, so we just assumed that every edge in the graph has a weight of 1. As a result, we did not encounter any negative weight cycles, so this algorithm was the most optimal solution. The runtime of this algorithm is **O(mlog(n))**.
<br>
To test our implementation, we checked that our algorithm returns the shortest path for a graph that we constructed manually.

## Betweenness Centrality
In our project, a betweenness centrality algorithm was used to find the most influential person in the social network. The way this algorithm works is that it finds the number of times this node occurs in the shortest path. If the node occurs in the shortest path between two nodes, 1 is added to its centrality. If there are multiple shortest paths between two nodes, the algorithm adds the number of times that occurs between those paths divided by the number of shortest paths. The runtime of our betweenness centrality algorithm is **O(mn+n^2)**.

# Response to the Leading Question
As described in our project proposal, our leading question was primarily focused on identifying the most influential person in a social network. However, we also wanted to find the number of connections between this individual and a random person in the network.
<br>
In order to answer this question, we used betweenness centrality to find the most influential person, BFS/DFS to identify a random person that is connected to the most influential person, and Dijkstra’s algorithm to find the shortest path between these two people.
<br>
Overall, by doing this project, we learned more about the betweenness centrality algorithm because it was not an algorithm that we had learned during class. When we ran our implementation with approximately 25% of the entire dataset or about 20,000 vertices, we found that the most influential person was the individual at index 107. This individual has a direct edge to the person at index 1014, which we found by running BFS from index 107.

# Results of Running the Algorithms
As shown by the image below, our algorithms pass all of the 7 tests cases that we have written. To view our code for the test cases, please refer to tests.cpp in the tests folder. In addition, we have also included a picture of our output after running our implementation with 20,000 vertices, as briefly described above.
<br>
<br>
![image](https://user-images.githubusercontent.com/30820292/206884101-842c7fc0-49dc-43e4-94c2-127f312dfd53.png)
<br>
<br>
![image](https://user-images.githubusercontent.com/30820292/206884395-fc934bf2-bd70-4dcd-ad3e-fbdd52ed3013.png)
