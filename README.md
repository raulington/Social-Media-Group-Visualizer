# Social-Media-Group-Visualizer
In a given social network, who is the most influential person on the network, or the individual in the most friend groups, based on their number of connections? Also, for a random person on the network, how many connections separate this person and the most popular person? 

The team will use the dataset, assign a weight of 1 to each edge, and first use the Betweenness Centrality algorithm to determine the most popular person. Then, we will utilize Dijkstra’s Algorithm to find the number of connections that are between a random user of the network and the most influential user.

# Location of all major files
Test files are under test and can be run with
./test

All major files are under the src directory

The main.cpp file is in the entry directory 

# Running project
To run the project, run the following command lines:

mkdir build

cd build

cmake ..

./main
