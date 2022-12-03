#include "Dijkstra.h"
#include <iostream>
#include "PriorityQueue.h"

std::vector<std::vector<std::string>> Dijkstra::algorithm(std::string vertex1, std::string vertex2) {
    std::unordered_map<std::string, std::string> tmp;
    std::queue<std::string> queue;
    for (auto i : map_[vertex1]) {
        queue.push(i);
    }
    std::vector<std::string> tmp2;
    std::string tmp3;

    while(queue.empty() == false) {
        tmp3 = queue.front();
        queue.pop();
        for (auto i : map_[tmp3]) {
            bool flag = true;
            for (auto j : tmp2) {
                if (i == j) {
                    flag = false;
                    break;
                }
            }
            if (flag == true) {
                tmp[i] = tmp3;
                queue.push(i);
            }
        }
        tmp2.push_back(tmp3);
    }
    std::vector<std::vector<std::string>> tmp4;
    std::vector<std::string> tmp5;
    std::string tmp6;
    for (auto i : tmp) {
        tmp6 = i.second;
        tmp5.clear();
        tmp5.push_back(i.first);
        tmp5.push_back(i.second);
        while (tmp.find(tmp6) != tmp.end()) {
            tmp5.push_back(tmp6);
            tmp6 = tmp[tmp6];
        }
        tmp5.push_back(tmp6);
        tmp4.push_back(tmp5);
    }
    return tmp4;
}

std::vector<std::vector<std::string>> Dijkstra::algorithm2(std::string vertex1, std::string vertex2) {
    std::unordered_map<std::string, int> tmp1;
    std::unordered_map<std::string, std::string> tmp2;
    for (auto i : map_) {
        tmp1[i.first] = 2;
        tmp2[i.first] = "";
    }
    tmp1[vertex1] = 0;
    PriorityQueue queue;
    queue.buildheap(tmp1);
    std::vector<std::string> tmp3;
    std::string tmp4;
    bool flag;
    std::vector<std::vector<std::string>> tmp5;
    while (queue.isempty() == false) {
        tmp4 = queue.peek();
        tmp3.push_back(tmp4);
        for (auto i : map_[tmp4]) {
            flag = true;
            for (auto j : tmp3) {
                if (i == j) {
                    flag = false;
                    break;
                }
            }
            if (flag == false) {
                continue;
            }
            tmp3.push_back(i);
            if (tmp1[i] == 2) {
                tmp1[i] = 1;
                tmp2[i] = tmp4;
                if (i == vertex2) {
                    std::vector<std::string> tmp6;
                    std::string tmp7 = i;
                    while (tmp2.find(tmp7) != tmp2.end()) {
                        tmp6.push_back(tmp7);
                        tmp7 = tmp2[tmp7];
                    }
                    tmp6.push_back(tmp7);
                    //tmp5.push_back(tmp6);
                    //return tmp5;
                    if (tmp5.size() == 0) {
                        tmp5.push_back(tmp6);
                        continue;
                    }
                    if (tmp6.size() < tmp5.at(0).size()) {
                        tmp5.clear();
                        tmp5.push_back(tmp6);
                        continue;
                    }
                    if (tmp6.size() == tmp5.at(0).size()) {
                        tmp5.push_back(tmp6);
                        continue;
                    }
                }
            }
        }
        tmp4 = queue.pop(tmp1);
    }
    return tmp5;
}