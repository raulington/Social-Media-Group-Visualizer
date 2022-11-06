#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
    std::string tmp2;
    std::vector<std::string> tmp;
    std::ifstream file("facebook_combined.txt");
    while (getline(file, tmp2)) {
        tmp.push_back(tmp2);
    }
    file.close();

}