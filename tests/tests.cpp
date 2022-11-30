#include <catch2/catch_test_macros.hpp>
#include "./Between.h"
#include "./BFS.h"


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

  REQUIRE( bfs.peek() == "start" );
  REQUIRE( bfs.peek() == "one" );
  REQUIRE( bfs.peek() == "two" );
  REQUIRE( bfs.peek() == "three" );
  REQUIRE( bfs.peek() == "four" );
}

// Cases for betweenness based on the following youtube video: https://www.youtube.com/watch?v=ptqt2zr9ZRE
TEST_CASE("Betweeness case 1", "[weight=1][part=1][valgrind]") {
    std::unordered_map<std::string, std::vector<std::string>> map;
    std::string A = "A";
    std::string B = "B";
    std::string C = "C";
    std::string D = "D";
    std::string E = "E";
    std::string F = "F";

    std::vector<std::string> Aneighbors;
    Aneighbors.insert(Aneighbors.end(), { B, C });
    map.insert(std::make_pair(A, Aneighbors));

    std::vector<std::string> Bneighbors;
    Bneighbors.insert(Bneighbors.end(), { A, C });
    map.insert(std::make_pair(B, Bneighbors));

    std::vector<std::string> Cneighbors;
    Cneighbors.insert(Cneighbors.end(), { A, B, D });
    map.insert(std::make_pair(C, Cneighbors));

    std::vector<std::string> Eneighbors;
    Eneighbors.insert(Eneighbors.end(), { D, F });
    map.insert(std::make_pair(E, Eneighbors));

    std::vector<std::string> Fneighbors;
    Fneighbors.insert(Fneighbors.end(), { D, E });
    map.insert(std::make_pair(F, Fneighbors));

    std::vector<std::string> Dneighbors;
    Dneighbors.insert(Dneighbors.end(), { C, E, F });
    map.insert(std::make_pair(D, Dneighbors));

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
    std::unordered_map<std::string, std::vector<std::string>> map;
    std::string A = "A";
    std::string B = "B";
    std::string C = "C";
    std::string D = "D";
    std::string E = "E";
    std::string F = "F";

    std::vector<std::string> Aneighbors;
    Aneighbors.insert(Aneighbors.end(), { E, B });
    map.insert(std::make_pair(A, Aneighbors));

    std::vector<std::string> Bneighbors;
    Bneighbors.insert(Bneighbors.end(), { A, C, D });
    map.insert(std::make_pair(B, Bneighbors));

    std::vector<std::string> Cneighbors;
    Cneighbors.insert(Cneighbors.end(), { B, D, F });
    map.insert(std::make_pair(C, Cneighbors));

    std::vector<std::string> Eneighbors;
    Eneighbors.insert(Eneighbors.end(), { F, A });
    map.insert(std::make_pair(E, Eneighbors));

    std::vector<std::string> Fneighbors;
    Fneighbors.insert(Fneighbors.end(), { C, E });
    map.insert(std::make_pair(F, Fneighbors));

    std::vector<std::string> Dneighbors;
    Dneighbors.insert(Dneighbors.end(), { C, B });
    map.insert(std::make_pair(D, Dneighbors));

    Between b(map);

    std::unordered_map<std::string, double> cmap = b.centralities();
    REQUIRE(cmap.at(A) == 1.5);
    REQUIRE(cmap.at(B) == 2.5);
    REQUIRE(cmap.at(C) == 2.5);
    REQUIRE(cmap.at(D) == 0);
    REQUIRE(cmap.at(E) == 1);
    REQUIRE(cmap.at(F) == 0.5);
}