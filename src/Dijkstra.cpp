#include "Dijkstra.h"

std::vector<std::vector<std::string>> Dijkstra::algorithm(std::string vertex1, std::string::string vertex2) {
    std::map<std::string, std::string> tmp;
    std::queue<std::string> queue;
    for (auto i : map[vertex1]) {
        queue.push(i);
    }
    std::vector<std::string> tmp2;
    std::string tmp3;

    while(queue.empty() == false) {
        tmp3 = queue.front;
        queue.pop();
        for (auto i : map_(tmp3)) {
            flag = true;
            for (auto j : tmp2) {
                if (i == j) {
                    flag = false;
                    break;
                }
            }
            if (flag == true) {
                tmp[i] = tmp3;
                queue.push(i)
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