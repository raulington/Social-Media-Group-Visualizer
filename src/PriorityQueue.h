#include <unordered_map>
#include <vector>
#include <string>

class PriorityQueue {
    public:
        PriorityQueue();
        void buildheap(std::unordered_map<std::string, int> tmp);
        void heapifyup(unsigned int tmp, std::unordered_map<std::string, int> tmp2);
        void heapifydown(unsigned int tmp, std::unordered_map<std::string, int> tmp2);
        void push(std::string, std::unordered_map<std::string, int> tmp2);
        std::string pop(std::unordered_map<std::string, int> tmp);
        bool isempty();
        std::string peek();
    //private:
        std::vector<std::string> vector;
};