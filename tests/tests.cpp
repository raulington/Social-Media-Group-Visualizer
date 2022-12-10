#include <catch2/catch_test_macros.hpp>
#include "./Between.h"
#include "./Dijkstra.h"
#include "./BFS.h"
#include "./DFS.h"

// Cases for DFS
TEST_CASE("DFS maintains the deepest point on top", "[weight=0][part=1][part=1a][valgrind]") {

  std::unordered_map<std::string, std::vector<std::string>> graph;
  std::string startPoint("start");

  DFS dfs(graph, startPoint, 5);
  dfs.add("one");
  dfs.add("two");
  dfs.add("three");
  dfs.add("four");

  REQUIRE( dfs.peek() == "four" );
}

TEST_CASE("DFS maintains a depth-first ordering", "[weight=0][part=1][part=1b][valgrind]") {

  std::unordered_map<std::string, std::vector<std::string>> graph;
  std::string startPoint("start");

  DFS dfs(graph, startPoint, 5);
  dfs.add("one");
  dfs.add("two");
  dfs.add("three");
  dfs.add("four");

  REQUIRE( dfs.pop() == "four" );
  REQUIRE( dfs.pop() == "three" );
  REQUIRE( dfs.pop() == "two" );
  REQUIRE( dfs.pop() == "one" );
  REQUIRE( dfs.pop() == "start" );
}

// Cases for BFS
TEST_CASE("BFS maintains the correct point on top", "[weight=0][part=1][part=1a][valgrind]") {

  std::unordered_map<std::string, std::vector<std::string>> graph;
  std::string startPoint("start");

  BFS bfs(graph, startPoint, 5);
  bfs.add("one");
  bfs.add("two");
  bfs.add("three");
  bfs.add("four");

  REQUIRE( bfs.peek() == "start" );
}

TEST_CASE("BFS maintains the BFS ordering", "[weight=0][part=1][part=1b][valgrind]") {

  std::unordered_map<std::string, std::vector<std::string>> graph;
  std::string startPoint("start");

  BFS bfs(graph, startPoint, 5);
  bfs.add("one");
  bfs.add("two");
  bfs.add("three");
  bfs.add("four");

  REQUIRE( bfs.pop() == "start" );
  REQUIRE( bfs.pop() == "one" );
  REQUIRE( bfs.pop() == "two" );
  REQUIRE( bfs.pop() == "three" );
  REQUIRE( bfs.pop() == "four" );
}

// Cases for betweenness based on the following youtube video: https://www.youtube.com/watch?v=ptqt2zr9ZRE
TEST_CASE("Betweeness case 1", "[weight=1][part=1][valgrind]") {
    std::unordered_map<std::string, std::vector<std::string>> map = {{"A", {"B", "C"}},
                                                                      {"B", {"A", "C"}},
                                                                      {"C", {"A", "B", "D"}},
                                                                      {"D", {"C", "E", "F"}},
                                                                      {"E", {"D", "F"}},
                                                                      {"F", {"D", "E"}}};
    std::string A = "A";
    std::string B = "B";
    std::string C = "C";
    std::string D = "D";
    std::string E = "E";
    std::string F = "F";


    Between b(map);
    std::unordered_map<std::string, double> cmap = b.centralities();

    REQUIRE(cmap.at(A) == 0);
    REQUIRE(cmap.at(B) == 0);
    REQUIRE(cmap.at(C) == 6);
    REQUIRE(cmap.at(D) == 6);
    REQUIRE(cmap.at(E) == 0);
    REQUIRE(cmap.at(F) == 0);
}

TEST_CASE("Betweeness case 2", "[weight=1][part=1][valgrind]") {
    std::unordered_map<std::string, std::vector<std::string>> map = {{"A", {"E", "B"}},
                                                                      {"B", {"A", "C", "D"}},
                                                                      {"C", {"B", "D", "F"}},
                                                                      {"D", {"C", "B"}},
                                                                      {"E", {"F", "A"}},
                                                                      {"F", {"C", "E"}}};
    std::string A = "A";
    std::string B = "B";
    std::string C = "C";
    std::string D = "D";
    std::string E = "E";
    std::string F = "F";

    Between b(map);
    std::unordered_map<std::string, double> cmap = b.centralities();

    REQUIRE(cmap.at(A) == 1.5);
    REQUIRE(cmap.at(B) == 2.5);
    REQUIRE(cmap.at(C) == 2.5);
    REQUIRE(cmap.at(D) == 0);
    REQUIRE(cmap.at(E) == 1);
    REQUIRE(cmap.at(F) == 1.5);
}


TEST_CASE("Dijkstra case", "[weight=1][part=1][valgrind]") {
    std::unordered_map<std::string, std::vector<std::string>> map = {{"A", {"E", "B"}},
                                                                      {"B", {"A", "C", "D"}},
                                                                      {"C", {"B", "D", "F"}},
                                                                      {"D", {"C", "B"}},
                                                                      {"E", {"F", "A"}},
                                                                      {"F", {"C", "E"}}};

    Dijkstra d(map);
    std::vector<std::vector<std::string>> EDpaths = d.shortest_paths("E", "D");
    std::vector<std::vector<std::string>> EDTrue = {{"D", "B", "A", "E"}, {"D", "C", "F", "E"}};
    std::vector<std::vector<std::string>> BEpaths = d.shortest_paths("B", "E");
    std::vector<std::vector<std::string>> BETrue = {{"E", "A", "B"}};
    std::vector<std::vector<std::string>> CApaths = d.shortest_paths("C", "A");
    std::vector<std::vector<std::string>> CATrue = {{"A", "B", "C"}};

    REQUIRE(CApaths == CATrue);
    REQUIRE(BEpaths == BETrue);
    REQUIRE(EDpaths == EDTrue);
}

