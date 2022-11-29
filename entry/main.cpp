#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>

int main() {
    std::string tmp2;
    std::string tmp3;
    std::string tmp4;
    std::unordered_map<std::string, std::vector<std::string>> tmp;
    std::ifstream file("facebook_combined.txt");
    while (getline(file, tmp2)) {
        tmp3 = tmp2.substr(0, tmp2.find(" "));
        tmp4 = tmp2.substr(tmp2.find(" "), tmp2.size());
        tmp[tmp3].push_back(tmp4);
        tmp[tmp4].push_back(tmp3);
    }
    file.close();

}