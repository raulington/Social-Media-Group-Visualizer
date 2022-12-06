#include "PriorityQueue.h"
#include <iostream>

PriorityQueue::PriorityQueue() {
    vector.push_back("");
}

void PriorityQueue::buildheap(std::unordered_map<std::string, int> tmp) {
    for (auto i : tmp) {
        vector.push_back(i.first);
    }
    for (int i = vector.size() - 1; i > 0; i--) {
        heapifydown(i, tmp);
    }
}

void PriorityQueue::heapifyup(unsigned int tmp, std::unordered_map<std::string, int> tmp2) {
    if (tmp > 1) {
        if (tmp2[vector.at(tmp)] < tmp2[vector.at(tmp/2)]) {
            std::swap(vector.at(tmp), vector.at(tmp/2));
            heapifyup(tmp/2, tmp2);
        }
    }
}

void PriorityQueue::heapifydown(unsigned int tmp, std::unordered_map<std::string, int> tmp2) {
    if (tmp * 2 < vector.size()) {
        //std::cout<<vector.at(tmp)<<std::endl;
        //std::cout<<tmp2[vector.at(tmp)]<<std::endl;
        int num = tmp * 2;
        if (tmp * 2 + 1 < vector.size()) {
            if (tmp2[vector.at(tmp * 2 + 1)] < tmp2[vector.at(tmp * 2)]) {
                num = tmp * 2 + 1;
            }
        }
        if (tmp2[vector.at(tmp)] > tmp2[vector.at(num)]) {
            std::swap(vector.at(tmp), vector.at(num));
            heapifydown(num, tmp2);
        }
    }
}

void PriorityQueue::push(std::string tmp, std::unordered_map<std::string, int> tmp2) {
    vector.push_back(tmp);
    heapifyup(vector.size() - 1, tmp2);
}

std::string PriorityQueue::pop(std::unordered_map<std::string, int> tmp) {
    std::string tmp2 = vector.at(1);
    std::swap(vector.at(1), vector.at(vector.size() - 1));
    vector.pop_back();
    heapifydown(1, tmp);
    return tmp2;
}

bool PriorityQueue::isempty() {
    if (vector.size() == 1) {
        return true;
    }
    return false;
}

std::string PriorityQueue::peek() {
    return vector.at(1);
}